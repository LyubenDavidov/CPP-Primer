// amzi_fit.hpp
#pragma once

#include <string>
#include <vector>

// ----------------- parameter structs -----------------

struct InitialGuess {
    double P0;
    double C;
    double phi0;
    double Vpi;
    double alpha;
    double beta;
    double gamma;
};

struct FitParams {
    double P0;
    double C;
    double phi0;
    double Vpi;
    double alpha;
    double beta;
    double gamma;
};

// residuals etc.
struct FitResult {
    FitParams params;

    std::vector<double> voltage;    // V
    std::vector<double> power_mW;   // measured
    std::vector<double> model_mW;   // fitted
    std::vector<double> residuals;  // model - data (mW)

    double rss;  // residual sum of squares
    double rms;  // root-mean-square residual
};

// how to handle plotting
enum class PlotMode {
    None,         // no plot
    ShowOnly,     // show ROOT canvas
    SaveOnly,     // create canvas, save to file, don't rely on Run()
    ShowAndSave   // both
};

/**
 * Fit AMZI model to a .npy file containing power in dBm.
 *
 * - npy_path: path to 1D .npy file (power vs voltage sweep)
 * - guess: initial parameter guesses
 * - plot_mode: whether to make/show/save a ROOT plot
 * - out_path: if non-empty and plot_mode is SaveOnly/ShowAndSave,
 *             save as this file (e.g. "plot.pdf" or "plot.png")
 *
 * Assumes a TApplication exists in main if you use Show* modes.
 */
FitResult fit_amzi_file(const std::string& npy_path,
                        const InitialGuess& guess,
                        PlotMode plot_mode = PlotMode::None,
                        const std::string& out_path = "");
