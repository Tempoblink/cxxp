/*
 * 根据自己的理解写出Sales_data类，最好与书中的例子有所区别
 */

#include <iostream>
#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = {0};
    double revenue = {0.0};
};

int main(void) {
    Sales_data item;
    std::cout << item.units_sold << std::endl;
    std::cout << item.revenue << std::endl;
    return 0;
}
