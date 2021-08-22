/*
 * 对于Sales_data的输入运算符来说，如果给定了下面的输入将发生什么情况？
 *
 * (a) 0-201-99999-9 10 24.95
 * (b) 10 24.95 0-210-99999-9
 */

/*
 * (a) 正常输入
 * (b) 读取bookNo时读取失败，对象被设置成默认状态。
 */

#include "include/Sales_data.h"
#include <iostream>

int main(int argc, char const *argv[]) {
    Sales_data b1, b2;
    std::cin >> b1;
    std::cin >> b2;
    return 0;
}
