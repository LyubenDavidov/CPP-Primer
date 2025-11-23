/**
 * This is a short script showing how to load 
 * npy files using the xtensor library. The 
 * .npy file is loaded as xtensor array. 
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

int main(int argc, char* argv[]) {
    // ----- print the usage of the program -----
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <npy_file_path>" << std::endl;
        return 1;
    }
    std::string const npy_file_path{argv[1]};

    // ----- load the 1D array from the npy file -----
    xt::xarray<double> const double_array{xt::load_npy<double>(npy_file_path)};

    // ----- get the shape of the array -----
    auto const& shape = double_array.shape();

    // ----- check that it is 1D array -----
    if (shape.size() != 1)
    {
        std::cerr << "Expected a 1D array, got: " << shape.size() << "D.\n";
        return 1;
    }

    // ----- check length of the array -----
    std::size_t const N = shape[0];
    std::cout << "Loaded 1D array with " << N << " elements.\n\n";

    return 0;
}
