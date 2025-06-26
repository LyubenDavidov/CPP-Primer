// SCRIPT TO SHOWCASE CONST
#include <iostream>

int main() {
    const int BufSize = 512;
    
    // reference to const cannot be used to change the object
    const int &refBufSize = BufSize;

    // pointer to constant
    const int *pBufSize =  &BufSize;

    // print the pointer
    std::cout << pBufSize << std::endl;

    // constant pointer to constant variable
    const double pi = 3.14159;

    // constant pointer
    const double *const pip = &pi;

    // print pi address
    std::cout << pip << std::endl; // neither the value of pi or the address can be changed

    // type aliases
    typedef double wages;
    typedef wages base , *p;  // p is now an alias for pointer to wages that is an alias for double

    wages my_wage = 5000.79;
    p p2my_wage = &my_wage;

    // print my wage and the address to it
    std::cout << my_wage << std::endl;
    std::cout << p2my_wage << std::endl;
    std::cout << *p2my_wage << std::endl;


    // example direct initialization and copy initialization
    std::string str0 = "hiya"; // copy initialization
    std::string str1 ("hiya"); // direct initialization

    // print them
    std::cout << "Copy initialization: " << str0 << std::endl;
    std::cout << "Direct initialization: " << str1 << std::endl;

    return 0;
}

