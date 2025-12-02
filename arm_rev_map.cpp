/**
 * Loads the .npy arrays containing the optimization voltages
 * for the 8 AMZI arms for all wavelength points. Plots the 
 * voltage vs wavelength signal for a particular arm of choice
 */

 #include <istream>
 #include <fstream>
 #include <iostream>


// ----- xtensor library -----
#include <xtensor/containers/xarray.hpp>
#include <xtensor/io/xio.hpp>
#include <xtensor/io/xnpy.hpp>

// ----- matplot++ -----
#include <matplot/matplot.h>

// ----- utility -----
#include <cmath>
#include <vector>


// ----- path to measurements -----

int main() {
    auto data = xt::load_npy<double>("in.npy");
    return 0;
}