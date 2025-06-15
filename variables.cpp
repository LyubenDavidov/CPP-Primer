// SOME SHORT VARIABLES AND TYPES EXERCISE
#include <iostream>


int main() {
    // declare some signed and unsigned integers
    unsigned u0 = 10, u1 = 42;
    std::cout << u1 - u0 << std::endl; //out: 32
    std::cout << u0 - u1 << std::endl; //out: 4294967264 (2^32) + (10-42) wrapped output 32 bit system

    int i0 = 10, i1 = 42;
    std::cout << i1 - i0 << std::endl; //out: 32
    std::cout << i0 - i1 << std::endl; //out: -32
    return 0;
}