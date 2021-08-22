/*
 * 基于上一个练习中的变量和语句编写一段程序，输出赋值前后变量的内容，你刚才的推断正确吗？
 */

#include <iostream>

int main(void) {
    int i = 0, &r = i;
    const int ci = i, &cr = ci;

    auto a = r;   //int
    auto b = ci;  //int
    auto c = cr;  //int
    auto d = &i;  //int *
    auto e = &ci; //const int *
    auto &g = ci; //cosnt &

    a = 42;
    std::cout << "a = " << a << std::endl;

    b = 42;
    std::cout << "b = " << b << std::endl;

    c = 42;
    std::cout << "c = " << c << std::endl;


    return 0;
}
