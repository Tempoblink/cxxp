/*
 * 编写程序，读取多条销售记录，并统计每个ISBN（每本书）有几条销售记录。
 */

#include "Sales_item.h"
#include <iostream>

int main(void) {
    Sales_item total;
    if (std::cin >> total) {
        int cnt = 1;
        Sales_item cur;
        while (std::cin >> cur) {
            if (total.isbn() == cur.isbn()) {
                ++cnt;
            } else {
                std::cout << total.isbn() << " has " << cnt
                          << " transaction(s)" << std::endl;
                total = cur;
                cnt = 1;
            }
        }
        std::cout << total.isbn() << " has " << cnt
                  << " transaction(s)" << std::endl;
    }
    return 0;
}
