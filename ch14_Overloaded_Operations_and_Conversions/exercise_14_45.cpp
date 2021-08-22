/*
 * 编写类型转换运算符将一个Sales_data对象分别转换成string和double，
 * 你认为这些运算符的返回值应该是什么？
 */

#include "include/Sales_data.h"
#include <iostream>


int main(int argc, char const *argv[]) {
    Sales_data book("0-201-78345-X");
    std::cout << static_cast<std::string>(book) << std::endl;
    std::cout << static_cast<double>(book) << std::endl;
    return 0;
}
