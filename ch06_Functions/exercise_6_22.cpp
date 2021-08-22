/*
 * 编写一个函数，令其交换两个int指针。
 */

#include <iostream>

//防止指针拷贝，应该用指向引用的指针。
void swap(int *&a, int *&b) {
    int *tmp = a;
    a = b;
    b = tmp;
}

int main(void) {
    int a = 1, b = 2;
    int *p = &a, *q = &b;
    std::cout << " a = " << a << " at " << reinterpret_cast<int_fast64_t>(&a) << std::endl;
    std::cout << " b = " << b << " at " << reinterpret_cast<int_fast64_t>(&b) << std::endl;

    std::cout << "*p = " << *p << " at " << reinterpret_cast<int_fast64_t>(&*p) << std::endl;
    std::cout << "*q = " << *q << " at " << reinterpret_cast<int_fast64_t>(&*q) << std::endl;
    swap(p, q);
    std::cout << "*p = " << *p << " at " << reinterpret_cast<int_fast64_t>(&*p) << std::endl;
    std::cout << "*q = " << *q << " at " << reinterpret_cast<int_fast64_t>(&*q) << std::endl;
    return 0;
}
