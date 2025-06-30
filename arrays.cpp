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

    // functions to find begin and end of an array
    string *beg     = begin(nums);
    string *last    = end(nums);

    // use array to initialize a vector
    int int_arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> ivec(begin(int_arr) , end(int_arr));

    // multidimensional arrays
    int ia0[3][4];          // 3 rows, 4 columns
    int ia1[10][20][30];    // 3d array

    // initializing elements of multidimensional array
    int ia2[3][4] = {
        {0, 3, 2, 6},   // row 1
        {8, 4, 9, 11},  // row 2
        {21, 8, 6, 3}   // row 3
    };

    return 0;
}
