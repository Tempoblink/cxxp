/*
 * 下面的静态数据成员的声明和定义有错误吗？请解释原因。
 *
 * --example.h
 * class Example {
 * public:
 *    static double rate = 6.5;
 *    static const int vecSize = 20;
 *    static vector<double> vec(vecSize);
 * };
 * --example.C
 * #include "example.h"
 * double Example::rate;
 * vector<double> Example::vec;
 */

#include <iostream>
#include <vector>

class Example {
public:
    constexpr static const double rate = 6.5;
    //可省略const
    //constexpr static double rate = 6.5;
    static const int vecSize = 20;
    //整型常量类型可省略 constexpr
    static std::vector<double> vec;
    //vector不是字面值类型，静态成员必须为字面值常量类型的constexpr
};

//即使一个常量静态数据成员在类内部被初始化了，通常情况下也应该在类的外部定义一下该成员。
constexpr double Example::rate;
std::vector<double> vec(Example::vecSize);
const int Example::vecSize;

int main(void) {
    return 0;
}
