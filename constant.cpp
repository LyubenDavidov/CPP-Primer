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

    return 0;
}

