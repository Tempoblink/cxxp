/*
 * 编写一个与用户交互的函数，要求用户输入一个数字，计算生成该数字的阶乘。
 * 在main函数中调用该函数。
 */

#include <iostream>
#include <limits>

int fact(void) {
    int val = 0, ret = 1;
    std::cout << "Enter a number: ";
    std::cin >> val;
    for (; val > 1; --val) {
        if (INT_MAX / val < ret) {
            std::cerr << "The number! is too high." << std::endl;
            exit(1);
        }
        ret *= val;
    }
    return ret;
}


int main(void) {
    int ret = fact();
    std::cout << "The result is " << ret << std::endl;
    return 0;
}
