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
    return 0;
}