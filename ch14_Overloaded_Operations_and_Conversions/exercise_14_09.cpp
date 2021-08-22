/*
 * 为你的Sales_data类定义输入运算符。
 */

#include "include/Sales_data.h"
#include <iostream>

int main(int argc, char const *argv[]) {
    std::cout << "Enter a book: ";
    Sales_data b1;
    std::cin >> b1;
    std::cout << b1 << std::endl;
    return 0;
}
