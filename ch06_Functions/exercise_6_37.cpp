/*
 * 为上一题的函数再写三个声明，
 * 一个使用类型别名，
 * 另一个使用尾置返回类型，
 * 最后一个使用decltype关键字。
 * 你觉得哪种形式最好？为什么？
 */

#include <iostream>
#include <string>

std::string (&func())[10];
//类型别名
using sarr = std::string[10];
sarr &func();
//后置返回类型
auto func() -> std::string (&)[10];
//使用decltype
std::string a[10];
decltype(a) &func();

int main(void) {
    return 0;
}
