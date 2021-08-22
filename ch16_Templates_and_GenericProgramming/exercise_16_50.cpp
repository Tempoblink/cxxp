/*
 * 定义上一个练习中的函数，令它们打印一条身份信息。运行该练习中的代码。如果函数调用的行为与你的预期不符，确定你了解原因。
 */

#include <iostream>

template<typename T>
void f(T) { std::cout << "f(T)" << std::endl; }
template<typename T>
void f(const T *) { std::cout << "f(const T*)" << std::endl; }
template<typename T>
void g(T) { std::cout << "g(T)" << std::endl; }
template<typename T>
void g(T *) { std::cout << "g(T*)" << std::endl; }

int main(int argc, char const *argv[]) {
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;
    g(42);
    g(p);
    g(ci);
    g(p2);
    f(42);
    f(p);
    f(ci);
    f(p2);
}
