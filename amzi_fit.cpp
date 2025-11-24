// amzi_fit.cpp
#include "amzi_fit.hpp"

// xtensor
#include <xtensor/containers/xarray.hpp>
#include <xtensor/io/xnpy.hpp>

// Eigen
#include <Eigen/Dense>
#include <unsupported/Eigen/NonLinearOptimization>
#include <unsupported/Eigen/NumericalDiff>

// ROOT (for plotting)
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TLegend.h"

#include <cmath>
#include <iostream>

// -------- Functor base (same as before) --------
template<typename _Scalar, int NX = Eigen::Dynamic, int NY = Eigen::Dynamic>
struct Functor {
    using Scalar = _Scalar;
    enum {
        InputsAtCompileTime  = NX,
        ValuesAtCompileTime  = NY
    };
    using InputType    = Eigen::Matrix<Scalar, InputsAtCompileTime, 1>;
    using ValueType    = Eigen::Matrix<Scalar, ValuesAtCompileTime, 1>;
    using JacobianType = Eigen::Matrix<Scalar, ValuesAtCompileTime, InputsAtCompileTime>;
    int m_inputs;
    int m_values;
    Functor(int inputs, int values) : m_inputs(inputs), m_values(values) {}
    int inputs() const { return m_inputs; }
    int values() const { return m_values; }
};

// -------- AMZI functor (same model as your code) --------
struct AMZIFunctor : Functor<double> {
    const Eigen::VectorXd& V;
    const Eigen::VectorXd& P;

    AMZIFunctor(const Eigen::VectorXd& V_in, const Eigen::VectorXd& P_in)
        : Functor<double>(7, static_cast<int>(V_in.size()))
        , V(V_in), P(P_in) {}

    int operator()(const Eigen::VectorXd &x, Eigen::VectorXd &fvec) const {
        double P0    = x[0];
        double C     = x[1];
        double phi0  = x[2];
        double Vpi   = x[3];
        double alpha = x[4];
        double beta  = x[5];
        double gamma = x[6];

        for (int i = 0; i < values(); ++i) {
            double Vi    = V[i];
            double phase = phi0 + M_PI * Vi / Vpi + gamma * Vi * Vi;
            double env   = 1.0 + alpha * Vi + beta * Vi * Vi;
            double fring = 1.0 + C * std::cos(phase);
            double model = P0 * env * fring;
            fvec[i] = model - P[i];
        }
        return 0;
    }
};

static inline double dBm_to_mW(double dBm) {
    return std::pow(10.0, dBm / 10.0);
}

FitResult fit_amzi_file(const std::string& npy_path,
                        const InitialGuess& guess,
                        PlotMode plot_mode,
                        const std::string& out_path)
{
    // ----- load npy (dBm) -----
    xt::xarray<double> adPwr = xt::load_npy<double>(npy_path);
    std::size_t N = adPwr.size();
    auto adVltg   = xt::linspace(0.0, -10.0, N+1);

    std::vector<double> vdVltg(N), vdPwr_dBm(N), vdPwr_mW(N);
    for (std::size_t i = 0; i < N; ++i) {
        vdVltg[i]    = adVltg(i);
        vdPwr_dBm[i] = adPwr(i);
        vdPwr_mW[i]  = dBm_to_mW(vdPwr_dBm[i]);
    }

    Eigen::VectorXd V = Eigen::Map<Eigen::VectorXd>(vdVltg.data(), N);
    Eigen::VectorXd P = Eigen::Map<Eigen::VectorXd>(vdPwr_mW.data(), N);

    // ----- set up LM -----
    AMZIFunctor functor(V, P);
    Eigen::NumericalDiff<AMZIFunctor> numDiff(functor);
    Eigen::LevenbergMarquardt<Eigen::NumericalDiff<AMZIFunctor>, double> lm(numDiff);

    Eigen::VectorXd x(7);
    x[0] = guess.P0;
    x[1] = guess.C;
    x[2] = guess.phi0;
    x[3] = guess.Vpi;
    x[4] = guess.alpha;
    x[5] = guess.beta;
    x[6] = guess.gamma;

    lm.parameters.maxfev = 200;
    lm.parameters.ftol   = 1e-8;
    lm.parameters.xtol   = 1e-8;

    auto status = lm.minimize(x);
    std::cout << "Fit " << npy_path << " status: " << int(status) << '\n';

    // ----- build model + residuals -----
    std::vector<double> vdModel(N), vdResidual(N);
    double rss = 0.0;
    for (std::size_t i = 0; i < N; ++i) {
        double Vi    = vdVltg[i];
        double phase = x[2] + M_PI * Vi / x[3] + x[6] * Vi * Vi;
        double env   = 1.0 + x[4] * Vi + x[5] * Vi * Vi;
        double fring = 1.0 + x[1] * std::cos(phase);
        double model = x[0] * env * fring;
        vdModel[i]   = model;
        vdResidual[i]= model - vdPwr_mW[i];
        rss += vdResidual[i] * vdResidual[i];
    }
    double rms = std::sqrt(rss / N);

    FitResult result;
    result.params = FitParams{x[0], x[1], x[2], x[3], x[4], x[5], x[6]};
    result.voltage   = std::move(vdVltg);
    result.power_mW  = std::move(vdPwr_mW);
    result.model_mW  = std::move(vdModel);
    result.residuals = std::move(vdResidual);
    result.rss = rss;
    result.rms = rms;

    // ----- optional ROOT plot -----
    if (plot_mode != PlotMode::None) {
        TCanvas* c = new TCanvas(("c_"+npy_path).c_str(),
                                 npy_path.c_str(), 800, 600);
        c->SetLeftMargin(0.12);
        c->ToggleEventStatus();

        int npoints = static_cast<int>(N);
        auto* g_data = new TGraph(npoints,
                                  result.voltage.data(),
                                  result.power_mW.data());
        g_data->SetTitle("Voltage vs Power; Voltage (V); Power (mW)");
        g_data->SetMarkerStyle(20);
        g_data->SetMarkerSize(1.0);
        g_data->SetMarkerColor(kBlue);
        g_data->GetXaxis()->CenterTitle(true);
        g_data->GetYaxis()->CenterTitle(true);
        g_data->Draw("AP");

        auto* g_model = new TGraph(npoints,
                                   result.voltage.data(),
                                   result.model_mW.data());
        g_model->SetLineColor(kRed);
        g_model->SetLineWidth(2);
        g_model->SetMarkerStyle(24);
        g_model->SetMarkerColor(kRed);
        g_model->Draw("LP SAME");

        auto* leg = new TLegend(0.15, 0.75, 0.45, 0.88);
        leg->AddEntry(g_data,  "Measured Data", "p");
        leg->AddEntry(g_model, "Model Fit",     "l");
        leg->SetFillStyle(0);
        leg->SetBorderSize(0);
        leg->SetTextSize(0.03);
        leg->Draw();

        c->Update();

        if ((plot_mode == PlotMode::SaveOnly ||
             plot_mode == PlotMode::ShowAndSave) &&
            !out_path.empty())
        {
            c->SaveAs(out_path.c_str());
        }
        // ShowOnly / ShowAndSave: you still call app.Run() in main.
    }

    return result;
}
