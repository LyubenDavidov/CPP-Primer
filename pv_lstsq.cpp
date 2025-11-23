/**
 * This script loads the .npy voltage vs power sweeps
 * and plots them.
 */


#include <cassert>
#include <iostream>
#include <string>

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

int main(int argc, char** argv) {

    TApplication app("app", &argc, argv);

    std::string const npy_file_path{"PV_arm1_pm_power_cwvl1550.0nm.npy"};


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
    std::vector<double> x(N), y(N);

    // ----- add the data to the arrays -----
    for (std::size_t i = 0; i < N; ++i)
    {
        x[i] = adVltg(i);     // applied voltage
        y[i] = adPwr(i);      // measured power
    }


    /*
     * =========================================
     * LEAST SQUARES POLYNOMIAL FIT TO THE DATA
     * =========================================
     */

    


    /*
     * ========================
     * PLOTTING ON ROOT CANVAS
     * ========================
     */

    // ----- create ROOT graph -----
    TCanvas* canva = new TCanvas("canva", "Voltage vs Power", 800, 600);
    canva->SetLeftMargin(0.12); 
    TGraph* graph = new TGraph(N, x.data(), y.data());

    graph->SetTitle("Voltage vs Power; Voltage (V); Power (dBm)");
    //graph->SetLineWidth(2);
    graph->SetMarkerStyle(20);
    graph->SetMarkerSize(1.0);
    graph->SetMarkerColor(kBlue);

    // ---- center axis labels ----
    graph->GetXaxis()->CenterTitle(true);
    graph->GetYaxis()->CenterTitle(true);

    graph->Draw("AP");

    canva->Update();
    app.Run();        // keeps the window open


    return 0;
}
