// PROGRAM TO READ OR WRITE SALESITEMS
#include <iostream>
#include "./source-files/1/Sales_item.h"

int main() {

    // define object of type Sales_item
    Sales_item book;

    // read ISBN, number of copies sold, and sales price
    std::cin >> book;

    // write ISBN, number of copies sold, total revenue, and average price
    std::cout << book << std::endl;

    return 0;
}