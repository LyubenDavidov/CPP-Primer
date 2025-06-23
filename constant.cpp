// SCRIPT TO SHOWCASE CONST
#include <iostream>

int main() {
    int val = 6;
    const int BufSize = 512;
    
    // reference to const cannot be used to change the object
    const int &refBufSize = BufSize;

    return 0;
}

