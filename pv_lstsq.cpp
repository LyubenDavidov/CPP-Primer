/**
 * This script loads the .npy voltage vs power sweeps
 * and plots them.
 */


#include <iostream>


// ----- file-stream library -----
#include <fstream>

// ----- xtensor library -----
#include <xtensor/containers/xarray.hpp>
#include <xtensor/io/xio.hpp>
#include <xtensor/io/xnpy.hpp>

// ----- ROOT -----
#include "TApplication.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TAxis.h" 
#include "TLegend.h"

// ----- utility -----
#include <cmath>
#include <vector>
#include <string>
#include <cassert>

// ----- EIGEN -----
#include "Eigen/Dense"
#include "unsupported/Eigen/NonLinearOptimization"
#include "unsupported/Eigen/NumericalDiff"



// Generic functor base (from Eigen docs)
template<typename _Scalar, int NX = Eigen::Dynamic, int NY = Eigen::Dynamic>
struct Functor {
    using Scalar = _Scalar;
    enum {
        InputsAtCompileTime  = NX,
        ValuesAtCompileTime  = NY
    };
    using InputType        = Eigen::Matrix<Scalar, InputsAtCompileTime, 1>;
    using ValueType        = Eigen::Matrix<Scalar, ValuesAtCompileTime, 1>;
    using JacobianType     = Eigen::Matrix<Scalar, ValuesAtCompileTime, InputsAtCompileTime>;

    int m_inputs;   // number of parameters
    int m_values;   // number of data points

    Functor() : m_inputs(InputsAtCompileTime), m_values(ValuesAtCompileTime) {}
    Functor(int inputs, int values) : m_inputs(inputs), m_values(values) {}

    int inputs() const { return m_inputs; }
    int values() const { return m_values; }
};





// Our AMZI fitting functor (residuals only; Jacobian via NumericalDiff)
struct AMZIFunctor : Functor<double> {
    const Eigen::VectorXd& V;  // voltages
    const Eigen::VectorXd& P;  // measured powers

    AMZIFunctor(const Eigen::VectorXd& V_in, const Eigen::VectorXd& P_in)
        : Functor<double>(5, static_cast<int>(V_in.size()))  // 5 parameters
        , V(V_in)
        , P(P_in)
    {}

    // x = [P0, C, phi0, Vpi]
    int operator()(const Eigen::VectorXd &x, Eigen::VectorXd &fvec) const {
        double P0       = x[0];
        double C        = x[1];
        double phi0     = x[2];
        double Vpi      = x[3];
        double alpha    = x[4];
        double beta     = x[5];
        double gamma    = x[6];

        for (int i = 0; i < values(); ++i) {
            double Vi   = V[i];
            // double envelope = std::exp(k * Vi);  // exponential amplitude decay
            double fringes  = 1.0 + C * std::cos(phi0 + M_PI * Vi / Vpi + gamma * pow(Vi,2));
            double model = P0 * (1 + alpha * Vi + beta * pow(Vi,2)) * fringes;
            fvec[i] = model - P[i];  // residual = model - data
        }
        return 0;
    }
};





int main(int argc, char** argv) {

    TApplication app("app", &argc, argv);

    std::string const npy_file_path{"PV_arm1_pm_power_cwvl1553.5nm.npy"};


    // ----- load the power 1D array from the npy file -----
    xt::xarray<double> const adPwr{xt::load_npy<double>(npy_file_path)};

    // ----- get the shape of the array -----
    auto const& size_adPwr = adPwr.size();

    // ----- number of points -----
    std::size_t const N = adPwr.size();

    // ----- create the voltage datapoints -----
    auto adVltg{xt::linspace(0.0, -10.0, N+1)};

    // ----- check: print voltage values -----
    for (size_t i{0}; i < size_adPwr; ++i)
    {
        std::cout << adPwr[i] << std::endl;
    }

    // ----- make ROOT-friendly arrays -----
    std::vector<double> vdVltg(N), vdPwr(N);

    // ----- add the data to the arrays -----
    for (std::size_t i = 0; i < N; ++i)
    {
        vdVltg[i] = adVltg(i);     // applied voltage
        vdPwr[i] = adPwr(i);      // measured power
    }

    std::vector<double> vdPwr_lin(N);
    for (int i = 0; i < N; ++i) {
        vdPwr_lin[i] = std::pow(10.0, vdPwr[i] / 10.0);  // assuming vdPwr is in dBm
    }

    // Suppose you have std::vector<double> volt, power;
    Eigen::VectorXd V = Eigen::Map<Eigen::VectorXd>(vdVltg.data(), vdVltg.size());
    Eigen::VectorXd P = Eigen::Map<Eigen::VectorXd>(vdPwr_lin.data(), vdPwr_lin.size());

    /*
     * =========================================
     * LEAST SQUARES POLYNOMIAL FIT TO THE DATA
     * =========================================
     */


    
    // ----- 2) Set up functor -----
    AMZIFunctor functor(V, P);
    Eigen::NumericalDiff<AMZIFunctor> numDiff(functor);
    Eigen::LevenbergMarquardt<Eigen::NumericalDiff<AMZIFunctor>, double> lm(numDiff);



    // ----- 3) Initial guess for parameters -----
    Eigen::VectorXd x(7);
    x[0] = 0.03;            // P0 guess
    x[1] = 0.42;            // C guess
    x[2] = 4.10;            // phi0 guess
    x[3] = 3.0;             // Vpi guess
    x[4] = 0.009;           // alpha guess
    x[5] = 0.0002;          // beta guess
    x[6] = -0.02;           // gamma guess

    lm.parameters.maxfev = 200;   // max function evaluations
    lm.parameters.ftol   = 1e-8;  // tolerance on function
    lm.parameters.xtol   = 1e-8;  // tolerance on x

    auto status = lm.minimize(x);

    std::cout << "LM status: " << int(status) << "\n";
    std::cout << "Fitted parameters:\n";
    std::cout << "P0   = "      << x[0] << "\n";
    std::cout << "C    = "      << x[1] << "\n";
    std::cout << "phi0 = "      << x[2] << "\n";
    std::cout << "Vpi  = "      << x[3] << "\n";
    std::cout << "alpha = "     << x[4] << "\n";
    std::cout << "beta = "      << x[5] << "\n";
    std::cout << "gamma = "     << x[6] << "\n";

    // You can now evaluate the fitted model at any V:
    double V_test = -5.0;
    double P_fit  = x[0] * (1 + x[4] * V_test + x[5] * pow(V_test, 2)) * (1.0 + x[1] * std::cos(x[2] + M_PI * V_test / x[3] + x[6] * pow(V_test,2)));
    std::cout << "Model at V = " << V_test << " V: P = " << P_fit << "\n";


    // ----- create data from model -----
    std::vector<double> vdPwrM(N);

    for (std::size_t i = 0; i < N; ++i)
    {
        vdPwrM[i] = x[0] * (1 + x[4] * vdVltg[i] + x[5] * pow(vdVltg[i],2)) * (1.0 + x[1] * std::cos(x[2] + M_PI * vdVltg[i] / x[3] + x[6] * pow(vdVltg[i],2)));
    }

    


    /*
     * ========================
     * PLOTTING ON ROOT CANVAS
     * ========================
     */

    // ----- create canvas -----
    TCanvas* canva = new TCanvas("canva", "Voltage vs Power", 800, 600);
    canva->SetLeftMargin(0.12); 

    // ----------------------------------------------------------
    // 1. Original measurement data
    // ----------------------------------------------------------
    TGraph* g_data = new TGraph(N, vdVltg.data(), vdPwr_lin.data());
    g_data->SetTitle("Voltage vs Power; Voltage (V); Power (mW)");
    g_data->SetMarkerStyle(20);
    g_data->SetMarkerSize(1.0);
    g_data->SetMarkerColor(kBlue);
    g_data->GetXaxis()->CenterTitle(true);
    g_data->GetYaxis()->CenterTitle(true);

    // First graph defines axes → draw first
    g_data->Draw("AP");     // A = axes, P = points


    // ----------------------------------------------------------
    // 2. Model curve (calculated values)
    // ----------------------------------------------------------
    TGraph* g_model = new TGraph(N, vdVltg.data(), vdPwrM.data());
    g_model->SetLineColor(kRed);
    g_model->SetLineWidth(2);
    g_model->SetMarkerStyle(24);     // optional: hollow marker
    g_model->SetMarkerColor(kRed);
    // Draw on top of existing axes
    g_model->Draw("LP SAME");        // L = line, P = points


    // ----------------------------------------------------------
    // OPTIONAL: Add a legend
    // ----------------------------------------------------------
    auto legend = new TLegend(0.15, 0.75, 0.45, 0.88);
    // x1=0.80, x2=0.97 → pushed almost fully to the right

    legend->AddEntry(g_data,  "Measured Data", "p");
    legend->AddEntry(g_model, "Model Fit",     "l");

    // Make legend visually clean
    legend->SetFillStyle(0);     // transparent background
    legend->SetBorderSize(0);    // no border

    // Increase text and symbol size
    legend->SetTextSize(0.030);     // default is ~0.025

    legend->Draw();


    canva->Update();
    app.Run();
}
