#include <iostream>
#include <vector>
#include "Sales_data.h"
using namespace std;

int main(){
    // conditional operator
    int val;
    cin >> val;

    // example operator precedence 
    cout << ((val < 10) ? "below 10" : "over 10") << endl; 


    // bitwise operator
    unsigned char bits = 0233;  // 0233 is an octal literal

    // bits promoted to int and shifted left by 8 bits
    int shifted_bits = bits << 31;

    // print the new integer value
    cout << shifted_bits << endl;

    // the sizeof operator (int is 4 bytes = 32 bits)
    constexpr size_t sz = sizeof(shifted_bits);
    cout << sz << endl;

    // the sizeof a class
    constexpr size_t szSalesData = sizeof(Sales_data);
    cout << szSalesData << endl;

    return 0;
}