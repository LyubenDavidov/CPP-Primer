// CHANGE VALUE OF A POINTER, CHANGE THE VALUE THE POINTER POINTS TO
#include <iostream>

int main() {
    // declare variable
    int val0 = 42;

    // pointer
    int *pval = &val0;

    // print address and value
    std::cout << "Value is: " << *pval << std::endl;    // star: dereferencing operator
    std::cout << "Address is: " << pval << std::endl;   // no star: address

    // change val0 through the pointer
    *pval = 35;

    // print original value
    std::cout << "New value of original variable is: " << val0 << std::endl;

    // print the address
    std::cout << "Address is unchanged: " << pval << std::endl;

    // declare different variable
    int val1 = 30;

    // change pointer to point to new variable
    pval = &val1;   // beware: cannot change to point to a different type variable

    // print address and value
    std::cout << "Value the pointer points to now is: " << *pval << std::endl;
    std::cout << "Address the pointer points to now is: " << pval << std::endl; 

    // void pointers
    void *vpval = &val1;

    // print address and value
    std::cout << "Address the void pointer points to is: " << vpval << std::endl; 


    return 0;
}