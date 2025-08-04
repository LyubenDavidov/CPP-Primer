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

// another option using decltype
int odd[]  = {1, 3, 5, 7};
int even[] = {0, 2, 4, 6};
decltype(odd) *arrPtr(int i)
{
    // returns a pointer to the array
    return (i % 2) ? &odd : &even;
}


int main(){
    arrT* p0 = func(1);
    for (int i = 0; i < 10; i++)
    {
        // prints the contents of the selected array
        cout << (*p0)[i] << endl;
    }

    auto p1 = arrPtr(2);
    for (int i = 0; i < 4; i++)
    {
        // prints the contents of the selected array
        cout << (*p1)[i] << endl;
    }
    return 0;
}