#include <iostream>
#include <vector>
using namespace std;

int main(){
    // conditional operator
    int val;
    cin >> val;

    // example operator precedence 
    cout << ((val < 10) ? "below 10" : "over 10") << endl; 
    return 0;
}