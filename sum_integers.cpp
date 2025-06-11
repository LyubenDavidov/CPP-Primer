// PROGRAM TO SUM INTEGERS 1 TO 10
#include <iostream>

int main()
{
    int sum = 0, val = 0;
    // keep executing the while as long as val is less than or equal to 10

    // make the user sum integers in a provided range
    int low_range, high_range;
    std::cout << "Enter two numbers for the lower and upper range of summing integers" << std::endl;
    std::cin >> low_range >> high_range;
    if (low_range >= high_range)
    {
        std::cout << "Error: Upper range border is lower/equal than/to lower range one. Terminating..." << std::endl;
        return 0;
    }


    while (val <= 10)
    {
        sum += val; // assign sum+val to sum
        ++val;      // increase val by 1
    }
    std::cout << "Sum of 1 to 10 inclusive is: " << sum << std::endl;
    return 0;
}