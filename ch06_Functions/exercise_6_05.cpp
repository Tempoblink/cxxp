/*
 * 编写一个函数输出其实参的绝对值
 */

#include <iostream>

int abs(int val) {
    return val < 0 ? -val : val;
}

int main(void) {
    std::cout << "abs(-1) = " << abs(-1) << std::endl;
    std::cout << "abs(1) = " << abs(1) << std::endl;
    return 0;
}
