// SCRIPT TO PLAY WITH COMPOUND TYPES
#include <iostream>


int main() {
    // define some variables
    int val = 42;

    // reference to the variable
    int &refval = val;
    /*
     * A reference is not an object
     * It is an alias (a different)
     * name for the same object.
     * Printing &refval gives the 
     * address. Printing refval gives
     * the object (value).
     */

    std::cout << "Value is: " << refval << std::endl;
    std::cout << "Address is: " << &refval << std::endl;

    // pointer to val, pointer contains the address 
    int *pval = &val;
    std::cout << "Value is: " << *pval << std::endl;
    std::cout << "Address is: " << pval << std::endl;
     



    return 0;
}