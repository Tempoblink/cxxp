/*
 * 编写一个函数，令其接受两个参数：一个是int型的数，另一个是int指针。
 * 函数比较int的值和指针所指的值，返回较大的那个。
 * 在该函数中指针的类型应该是什么？
 */

#include <iostream>

int Bigger(int a, const int *b) {
    return a > *b ? a : *b;
}

int main(void) {
    const int n = 10;
    std::cout << Bigger(5, &n) << std::endl;
    return 0;
}
