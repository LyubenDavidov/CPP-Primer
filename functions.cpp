#include <iostream>
#include <vector>
#include "factorial.hpp"
#include <string>
using namespace std;


int main(){
    int number = 8;
    cout << factorial(number) << endl;

    cout << "It also works with convertable types: " << endl;
    cout << factorial(3.14) << endl;

    cout << "Test the find_char() function\n" << endl;
    cout << "This is my string sentence. Find the \'f\' characters!" << endl;
    string s = "This is my string sentence. Find the \'f\' characters!";
    string::size_type ocr = 0;
    cout << "The position of \'f\' is: " << find_char(s, 'f', ocr) << endl;
    cout << "\'f\' has been found " << ocr << " times" << endl;
    return 0;
}

// I changed a little thing