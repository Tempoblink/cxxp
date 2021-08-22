/*
 * 借助Sales_item.h头文件，编译并运行本节给出的书店程序。
 */

#include "Sales_item.h"
#include <iostream>

int main(void) {
    Sales_item total;
    if (std::cin >> total) {
        Sales_item trans;
        while (std::cin >> trans) {
            if (total.isbn() == trans.isbn()) {
                total += trans;
            } else {
                std::cout << total << std::endl;
                total = trans;
            }
        }
        std::cout << total << std::endl;
    } else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}
