// PROGRAM THAT READS SEVERAL TRANSACTIONS
#include <iostream>
#include "./source-files/1/Sales_item.h"


int main() {
    Sales_item currItem, inputItem, storeItems;

    if (std::cin >> currItem) {
        storeItems = currItem;
        while (std::cin >> inputItem) {
            if (inputItem.isbn() == currItem.isbn()) {
                storeItems += inputItem;
            }
            else {
                std::cout << "Total: " << storeItems << std::endl;
                currItem = inputItem;
                storeItems = Sales_item();
                storeItems = currItem;
            }
        }
        std::cout << "Total: " << storeItems << std::endl;
    }
    return 0;
}