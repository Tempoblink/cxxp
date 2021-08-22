/*
 * 编写程序，读取多个具有相同ISBN的销售记录，输出所有记录的和。
 */

#include "Sales_item.h"
#include <iostream>

int main(void) {
    Sales_item total;
    if (std::cin >> total) {
        Sales_item cur;
        while (std::cin >> cur) {
            if (total.isbn() == cur.isbn()) {
                total += cur;
            } else {
                std::cout << total << std::endl;
                total = cur;
            }
        }
        std::cout << total << std::endl;
    } else {
        std::cerr << "No data!" << std::endl;
        return -1;
    }
    return 0;
}
