/*
 * 编写一个名为Chapter6.h的头文件，令其包含6.1节中的函数声明。
 */

#include "include/Chapter6.h"
#include <iostream>


int main(void) {
    return 0;
}


int fact(int val) {
    int ret = 1;
    for (; val > 1; --val) {
        ret *= val;
    }
    return ret;
}

int call_fact(void) {
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

int abs(int val) {
    return val < 0 ? -val : val;
}
