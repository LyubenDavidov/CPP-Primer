#include <iostream>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};


int main() {
    Sales_data data0, data1;

    // price to calculate revenue
    double price;

    // get data from user first transaction
    std::cin >> data0.bookNo >> data0.units_sold >> price;

    // calculate the revenue based on sold units/price
    data0.revenue = data0.units_sold * price;

    // get data from user second transaction
    std::cin >> data1.bookNo >> data1.units_sold >> price;

    // calculate the revenue based on sold units/price
    data1.revenue = data1.units_sold * price;


    
    return 0;
}