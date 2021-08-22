/*
 * 编写一个程序，从标准输入读取一个字符串，存入一个动态分配的字符数组中。
 * 描述你的程序如何处理变长输入。
 * 测试你的程序，输入一个超出你分配的数组长度的字符串。
 */

#include <iostream>
#include <memory>
#include <string>

int main(int argc, char const *argv[]) {
    std::string input;
    std::cin >> input;
    auto sz = input.length();
    std::unique_ptr<char[]> p(new char[sz]);
    for (size_t i = 0; i < sz; ++i) {
        p[i] = input[i];
    }

    for (size_t i = 0; i < sz; ++i) {
        std::cout << p[i];
    }
    std::cout << std::endl;
}
