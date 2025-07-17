#include <iostream>
#include "./source-files/1/Sales_item.h"
using namespace std;

int main(){
    Sales_item item0, item1;
    cin >> item0 >> item1;
    if (item0.isbn() != item1.isbn()){
        throw runtime_error ("Data must refer to the same ISBN!");
    }
    // if we are still here we can add the items
    cout << item0 + item1 << endl;

    // example ISBN item: 0-201-78345-X 3 20.00
    return 0;
}