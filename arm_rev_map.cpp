/**
 * Loads the .npy arrays containing the optimization voltages
 * for the 8 AMZI arms for all wavelength points. Exports the 
 * voltage vs wavelength signal for all the arms
 */

 #include <istream>
 #include <fstream>
 #include <iostream>
 #include <filesystem>


// ----- xtensor library -----
#include <xtensor/containers/xarray.hpp>
#include <xtensor/containers/xadapt.hpp>
#include <xtensor/io/xio.hpp>
#include <xtensor/io/xnpy.hpp>


// ----- matplot++ -----
#include <matplot/matplot.h>

// ----- utility -----
#include <cmath>
#include <vector>


// ----- path to measurements -----
const std::filesystem::path DATA_FOLDER =   "/Users/ldavidov/Documents/Repos/Tunable-Filter/"
                                            "paper-tunable-filter/12_11_2025/PV-REV-wavelength-scan";

// ----- path to saved processed data -----
const std::filesystem::path PROCESSED_DATA_FOLDER =     "/Users/ldavidov/Documents/Repos/Tunable-Filter/"
                                                        "paper-tunable-filter/12_11_2025/PV-REV-wavelength-scan/"
                                                        "processed-data";

int main() {

    for (int arm = 0; arm < 8; ++arm){
        // ----- wavelength array -----
        auto WVL_DATA   = xt::linspace(1530.0, 1570.0, 81);
        auto szWVL_DATA = WVL_DATA.size();

        // ----- arm voltage array -----
        double VLT_DATA[81] = {};

        // ----- read data and save arm voltage -----
        for (decltype(szWVL_DATA) i=0; i != szWVL_DATA; ++i){

            std::string FILE = std::format("REV_voltages_{:.1f}nm_iter2_bound_min10.0V_max0.0V.npy", WVL_DATA[i]);
            std::filesystem::path DATA_PATH = DATA_FOLDER / FILE;

            auto DATA = xt::load_npy<double>(DATA_PATH.string());
            VLT_DATA[i] = DATA[arm];
            std::cout << "Loaded data for wavelength: " << std::format("{:.1f}", WVL_DATA[i]) << std::endl;
        }

        // ----- convert arrays to std::vector<double> -----
        std::vector<double> vlt_data(std::begin(VLT_DATA), std::end(VLT_DATA));
        std::vector<double> wvl_data(std::begin(WVL_DATA), std::end(WVL_DATA));

        // ----- save output .npy to processed-data folder -----
        std::string OUTPUT_FILE = std::format("arm{}-rev-vlt-wvl.npy", arm+1);
        std::filesystem::path OUTPUT_FILE_PATH = PROCESSED_DATA_FOLDER / OUTPUT_FILE;

        // ----- save arm rev voltage at wavelengths
        auto OUT = xt::adapt(vlt_data);
        xt::dump_npy(OUTPUT_FILE_PATH.string(), OUT);

        // ----- initialize figure -----
        matplot::figure();

        // ----- create plot -----
        auto line = matplot::plot(wvl_data, vlt_data);

        // ----- make line 2 points thick -----
        line->line_width(2.0); 

        // ----- customize plot -----
        std::string sPlotTitle = std::format("Arm {}: Optimum Voltage At Optimization Wavelength", arm+1);
        matplot::title(sPlotTitle);
        matplot::xlabel("Wavelength [nm]");
        matplot::ylabel("Voltage [V]");
        
        // ----- save plot -----
        std::string PLOT_FILENAME = std::format("arm{}-volt-wvl.svg", arm+1);
        std::filesystem::path PLOT_FILE_PATH = PROCESSED_DATA_FOLDER / PLOT_FILENAME;
        matplot::save(PLOT_FILE_PATH.string());

    }
    
    return 0;
}