#include <iostream>
#include <vector>
using namespace std;

int main(){
    // count the number of grades in clusters
    unsigned scores[11] = {};
    unsigned grade;

    while (cin >> grade){
        if (grade <= 100){
            ++scores[grade/10];
        }
        else{
            cout << "Grade must be between 0 and 100. \nTerminating..." << endl;
            return -1;
        }
    }

    // print grade distribution
    for (auto i : scores){
        cout << i << " ";
    }
    cout << endl;


    // define fixed array size
    constexpr size_t array_size = 10; // constexpr: variable is evaluated at compile time, not runtime, size_t: unsigned int type used to define array/buffer sizes
    unsigned values[array_size];

    // pointers and arrays
    string nums[] = {"one", "two", "three", "four"};
    string *p0 = &nums[0];
    ++p0;   // p0 now points to nums[1]
    return 0;
}
