/*
 * 定义赋值运算符的一个新版本，使得我们能把一个表示ISBN的string赋给一个Sales_data对象。
 */

#include "include/Sales_data.h"
#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
    std::string name = "0-201-78345-X";
    Sales_data book;
    book = name;
    std::cout << book << std::endl;
    return 0;
}
