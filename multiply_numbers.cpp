// PROGRAM TO MULTIPLY TWO NUMBERS
#include <iostream>

int main()
{
    std::cout << "Enter two numbers to multiply:\n" << std::endl;   // endline flushes the buffer
    int v0 = 0, v1 = 0;
    std::cin >> v0 >> v1;                                           // the input operator returns itself
    std::cout << "The product of " << v0 << " and " << v1 << " is: " << v0*v1 << std::endl;
    return 0;
}
