/*
 * 编写一个lambda，捕获它所在函数的int，并接受一个int参数。
 * lambda应该返回捕获的int和int参数的和。
 */

#include <iostream>

int main(int argc, char const *argv[]) {
    int a = 1, b = 1;
    auto func = [b](int a) { return a + b; };
    std::cout << a << " + " << b << " = ";
    std::cout << func(a) << std::endl;
    return 0;
}
