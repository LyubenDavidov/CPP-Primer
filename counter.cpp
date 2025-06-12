// PROGRAM TO COUNT HOW MANY TIME A VALUE OCCURS
#include <iostream>

int main()
{
    // currVal is the number we're counting, we read new values into val
    int currVal = 0, val = 0;

    // read first number and ensure we have data to process
    if (std::cin >> currVal) {
        int cnt = 1;                // store the count for the current value we're processing
        while (std::cin >> val) {   // read the remaining numbers
            if (val == currVal) {   // if the values are the same
                ++cnt;              // add 1 to count
            }
            else {
                std::cout << currVal << " occurs " << cnt << " times" << std::endl;
                currVal = val;      // remember the new value
                cnt = 1;            // reset counter
            }
        }
        // remember to print the count for the last value in the file (if end-of-file occurs)
        std::cout << currVal << " occurs " << cnt << " times" << std::endl;
    }
    return 0;
}