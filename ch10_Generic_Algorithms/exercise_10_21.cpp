/*
 * 编写一个lambda，捕获一个局部int变量，并递减变量值，直至它变为0。
 * 一旦变量变为0，再调用lambda应该不再递减变量。
 * lambda应该返回一个bool值，指出捕获的变量是否为0。
 */

#include <iostream>

int main(int argc, char const *argv[]) {
    int a = 10;
    auto func = [a]() mutable -> bool {
        if (a)
            --a;
        return 0 == a;
    };
    while (!func()) {
        std::cout << "func() called." << std::endl;
    }
    return 0;
}
