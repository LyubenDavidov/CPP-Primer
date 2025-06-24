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
    std::cout << pip << std::endl;

    return 0;
}

