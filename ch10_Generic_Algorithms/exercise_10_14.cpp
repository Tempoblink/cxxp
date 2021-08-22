/*
 * 编写一个lambda，接受两个int，返回它们的和。
 */

#include <iostream>

int main(int argc, char const *argv[]) {
    auto func = [](int a, int b) { return a + b; };
    int a = 1, b = 1;
    std::cout << a << " + " << b << " = ";
    std::cout << func(a, b) << std::endl;
    return 0;
}
