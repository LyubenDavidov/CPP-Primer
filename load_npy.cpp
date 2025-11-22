#include <iostream>
#include <xtensor/containers/xarray.hpp>
#include <xtensor/io/xio.hpp>

int main() {
    xt::xarray<double> a = {{1.0, 2.0}, {3.0, 4.0}};
    std::cout << a << std::endl;
    return 0;
}
