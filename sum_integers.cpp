// PROGRAM TO SUM INTEGERS 1 TO 10
#include <iostream>

int main()
{
    int sum = 0, val = 0;
    // keep executing the while as long as val is less than or equal to 10

    // make the user sum integers in a provided range
    int lower_range, upper_range;
    std::cout << "Enter two numbers for the lower and upper range of summing integers" << std::endl;
    std::cin >> lower_range >> upper_range;
    if (lower_range >= upper_range)
    {
        std::cout << "Error: Upper range must be higher than lower range integer. Terminating..." << std::endl;
        return 0;
    }

    // calculate the iterations
    int val_range = upper_range - lower_range;

    while (val <= val_range)
    {
        sum += lower_range; // assign sum+val to sum
        ++val;              // increase val by 1
    }
    std::cout << "Sum of integers " << lower_range << " to " << upper_range << " inclusive is: " << sum << std::endl;
    return 0;
}