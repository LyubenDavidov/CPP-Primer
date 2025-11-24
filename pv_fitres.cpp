#include "TApplication.h"
#include "amzi_fit.hpp"
#include <iostream>


// ROOT (for plotting)
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TLegend.h"

int main(int argc, char** argv)
{
    TApplication app("app", &argc, argv);

    InitialGuess guess{
        0.03,   // P0
        0.42,   // C
        4.10,   // phi0
        3.0,    // Vpi
        0.009,  // alpha
        0.0002, // beta
        -0.02   // gamma
    };

    FitResult r = fit_amzi_file(
        "PV_arm1_pm_power_cwvl1553.5nm.npy",
        guess,
        PlotMode::ShowOnly
    );

    // "PV_arm1_pm_power_cwvl1553.5nm.pdf"

    std::cout << "RMS residual: " << r.rms << " mW\n";
    std::cout << "Vpi fitted:   " << r.params.Vpi << " V\n";

    // ----- compute phase from the fit -----
    std::size_t N = r.voltage.size();
    std::vector<double> phase_rad(N);

    for (std::size_t i = 0; i < N; ++i) {
        double V        = r.voltage[i];
        double phi0     = r.params.phi0;
        double Vpi      = r.params.Vpi;
        double gamma    = r.params.gamma;

        // same phase model as in AMZIFunctor:
        // phi(V) = phi0 + π * V / Vpi + gamma * V^2
        phase_rad[i] = phi0 + M_PI * V / Vpi + gamma * V * V;
    }

    TCanvas* c_phase = new TCanvas("c_phase", "Phase vs Voltage", 800, 600);
    c_phase->SetLeftMargin(0.12);
    c_phase->ToggleEventStatus();


    // ----- phase in radians -----
    TGraph* g_phase = new TGraph(
        static_cast<int>(N),
        r.voltage.data(),
        phase_rad.data()
    );

    g_phase->SetTitle("Phase vs Voltage; Voltage (V); Phase (rad)");
    g_phase->SetLineWidth(2);
    g_phase->SetLineColor(kMagenta + 1);
    g_phase->SetMarkerStyle(20);
    g_phase->SetMarkerSize(0.8);
    g_phase->SetMarkerColor(kMagenta + 1);

    g_phase->GetXaxis()->CenterTitle(true);
    g_phase->GetYaxis()->CenterTitle(true);

    g_phase->Draw("ALP");  // A: axes, L: line, P: points

    c_phase->Update();

    app.Run();  // to keep ROOT windows open
    return 0;
}