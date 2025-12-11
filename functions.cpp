#include <iostream>
#include <vector>
#include "factorial.hpp"
#include <string>
#include <cstdlib>
#include <cassert>
using namespace std;


// array parsing
void print(const int *beg, const int *end){
    while (beg != end){
        cout << *beg++ << endl;
    }
}



/*
 * Explanation: Instead of returning a copy of the shorter string,
 * this function returns a reference to the original string passed
 * in (s1 or s2). The shorter string is not copied.
 */

// ----- return shorter string -----
const string &shorterString(const string &s1, const string &s2){
    return s1.size() <= s2.size() ? s1 : s2;
}


// ----- example inline function -----
inline const string &inlshorterString(const string &s1, const string &s2){
    return s1.size() <= s2.size() ? s1 : s2;
}

// ----- example overloaded function -----
int add_num(int a, int b){
    int res = a + b;
    return res;
}


int add_num(int a, int b, int c){
    int res = a + b + c;
    return res;
}


// ----- example constant expression function -----
constexpr int new_sz() {return 42;}     // return type and parameter type must be literals

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

    // showcase array parsing
    int my_array[5] = {3, 2, 5, 6, 1};
    print(begin(my_array), end(my_array));

    // showcase shorter string function
    string str1 = "This is my long sentence";
    string str2 = "Short sentence";
    cout << inlshorterString(str1, str2) << endl;


    int int01 = 3;
    int int02 = 2;
    int int03 = 7;
    
    std::cout << "Adding two numbers: " << add_num(int01, int02) << std::endl;
    std::cout << "Adding three numbers: " << add_num(int01, int02, int03) << std::endl;

    // ----- example assert statement -----
    // ----- triggers if NDEBUG is undefined -----
    string word                 = "elephant";
    string::size_type threshold = 30;
    assert(word.size() > threshold);

    // ----- example debugging without NDEBUG -----
    if (word.size() < threshold) {
    std::cerr << "Error: " << __FILE__
              << "\n\tFunction: " << __func__
              << "\n\tLine: " << __LINE__
              << "\n\tCompiled on: " << __DATE__ << " at " << __TIME__
              << "\n\tWord read was: \"" << word << "\""
              << "\n\tReason: Length too short (threshold = " << threshold << ")\n";
}

    return EXIT_SUCCESS;
}
