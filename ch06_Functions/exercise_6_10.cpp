/*
 * 编写一个函数，使用指针形参交换两个整数的值。
 * 在代码中调用该函数并输出交换后的结果，以此验证函数的正确性。
 */


#include <iostream>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void) {
    int a = 1, b = 2;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    swap(&a, &b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    return 0;
}
