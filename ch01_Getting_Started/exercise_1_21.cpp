/*
 * 编写程序，读取两个ISBN相同的Sales_item对象，输出他们的和
 */

#include "Sales_item.h"
#include <iostream>

int main(void) {
    Sales_item item1, item2;
    std::cout << "Enter two books: ";
    std::cin >> item1 >> item2;
    if (item1.isbn() == item2.isbn()) {
        std::cout << item1 + item2 << std::endl;
        return 0;
    }
    else {
      std::cerr << "Data must refer to same ISBN"
        << std::endl;
      return -1;
    }
}
