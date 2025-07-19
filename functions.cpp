#include <iostream>
#include <vector>
#include "factorial.hpp"
using namespace std;


int main(){
    int number = 8;
    cout << factorial(number) << endl;

    cout << "It also works with convertable types: " << endl;
    cout << factorial(3.14) << endl;

    cout << "Fill parameter list" << endl;
    return 0;
}