// CHANGE VALUE OF A POINTER, CHANGE THE VALUE THE POINTER POINTS TO
#include <iostream>

int main() {
    // declare variable
    int val = 42;

    // pointer
    int *pval = &val;

    // print address and value
    std::cout << "Value is: " << *pval << std::endl;    // star: dereferencing operator
    std::cout << "Address is: " << pval << std::endl;   // no star: address

    return 0;
}