#include <iostream>
#include <vector>
using namespace std;

int factorial(int val){
    int ret = 1;
    while (val > 1){
        ret *= val--;
    }
    return ret;
}

int main(){
    int number = 8;
    cout << factorial(number) << endl;

    cout << "It also works with convertable types: " << endl;
    cout << factorial(3.14) << endl;
    return 0;
}