// PROGRAM TO SUM INTEGERS 1 TO 10
#include <iostream>

int main()
{
    int sum = 0, val = 0;
    // keep executing the while as long as val is less than or equal to 10
    while (val <= 10)
    {
        sum += val; // assign sum+val to sum
        ++val;      // increase val by 1
    }
    std::cout << "Sum of 1 to 10 inclusive is: " << sum << std::endl;
    return 0;
}