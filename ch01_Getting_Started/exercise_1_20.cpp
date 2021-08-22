/*
 * 包含头文件Sales_item.h，将它拷贝到自己的工作目录中。用它编写一个程序，读取一组书籍销售记录，将每条记录打印到标准输出上。
 */

#include "Sales_item.h"
#include <iostream>

int main(void) {
    Sales_item item;
    std::cout << "Enter a book infomation: ";
    while (std::cin >> item) {
        std::cout << item << std::endl;
    }
    return 0;
}
