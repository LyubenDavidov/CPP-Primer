#include <iostream>
#include <vector>
using namespace std;

using arrT = int[10];
//typedef int arrT[10];
arrT* func(int i){
    static arrT arrays[3] = 
    {
        {1, 2, 3, 4, 5, 6, 7, 8},
        {9, 10, 11, 12, 13, 14, 15},
        {16, 17, 18}
    };
    return &arrays[i % 3];
}

/*
 * Same shit but now with trailing return type
 * auto func(int i) -> int(*)[10] {
    static int arrays[3][10] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 0, 0},
        {9, 10, 11, 12, 13, 14, 15, 0, 0, 0},
        {16, 17, 18, 0, 0, 0, 0, 0, 0, 0}
    };
    return &arrays[i % 3];
}
 */

int main(){
    arrT* p = func(1);
    for (int i = 0; i < 10; i++)
    {
        // prints the contents of the selected array
        cout << (*p)[i] << endl;
    }
    return 0;
}