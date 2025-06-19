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
     * name for the same object.*
     */

     std::cout << &refval << std::endl;


    return 0;
}