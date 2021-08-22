/*
 * 标准库max函数有两个参数，它返回实参中的较大者。
 * 此函数有一个模板类型参数。
 * 你能在调用max时传递给它一个int和一个double吗？
 * 如果可以，如何做？如果不可以，为什么？
 */

#include <algorithm>
#include <iostream>

int main(int argc, char const *argv[]) {
    int i = 2;
    double d = 2.1;
    // 显式指定模版参数类型
    std::cout << std::max<double>(i, d) << std::endl;
    return 0;
}
