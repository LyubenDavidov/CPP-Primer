// PROGRAM TO ADD SALES ITEMS
#include <iostream>
#include "./source-files/1/Sales_item.h"


int main() {

    Sales_item item0, item1;
    std::cin >> item0 >> item1;
    std::cout << item0 + item1 << std::endl;
    return 0;
}

/* It is also possible to use system redirection
 * This lets us associate a named file with the 
 * standard input and the standard output:
 * $ add_sales_items <infile >outfile
 * assuming the $ sign is our system prompt and 
 * our addition programm has been compiled to an
 * executable file named add_sales_items.exe or
 * add_sales_items on a UNIX system. 
*/