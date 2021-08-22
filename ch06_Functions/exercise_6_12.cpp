/*
 * 改写6.2.1节中练习6.10（第188页）的程序，使用引用而非指针交换两个整数的值。
 * 你觉得哪种方法更易于使用呢？为什么？
 */

#include <iostream>

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main(void) {
    int a = 1, b = 2;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    return 0;
}

