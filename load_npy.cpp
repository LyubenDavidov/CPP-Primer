/**
 * This is a short script showing how to load 
 * npy files using the xtensor library. The 
 * .npy files are loaded as xtensor arrays. 
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

    // ----- load the 4D array from the npy file -----
    xt::xarray<double> const double_array{xt::load_npy<double>(npy_file_path)};

    // ----- get the shape of the array -----
    auto const& shape = double_array.shape();

    if (shape.size() != 1)
    {
        std::cerr << "Expected a 1D array, got: " << shape.size() << "D.\n";
        return 1;
    }

    std::size_t const N = shape[0];
    std::cout << "Loaded 1D array with " << N << " elements.\n\n";
    // ----- access the elements of the array using a pointer -----
    // double const* const ptr{double_array.data()};
    // for (size_t i{0}; i<double_array.size(); ++i)
    // {
    //     assert(ptr[i] == static_cast<float>(i));
    // }

    // bool data_type_mismatch{false};
    // try
    // {
    //     xt::xarray<int> const int_array{xt::load_npy<int>(npy_file_path)};
    // }
    // catch (std::runtime_error const& e)
    // {
    //     data_type_mismatch = true;
    // }
    // assert(data_type_mismatch);
    return 0;
}
