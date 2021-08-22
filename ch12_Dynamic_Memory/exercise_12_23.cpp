/*
 * 编写一个程序，连接两个字符串字面量，
 * 将结果保存在一个动态分配的char数组中。
 * 重写这个程序，连接两个标准库string对象。
 */

#include <cstring>
#include <iostream>
#include <memory>
#include <string>
#include <sys/_types/_size_t.h>

void func1() {
    const char str1[] = "Hello, ";
    const char str2[] = "World.";

    std::unique_ptr<char[]> p(new char[std::strlen(str1) + std::strlen(str2)]);
    for (size_t i = 0; i < std::strlen(str1); ++i) {
        p[i] = str1[i];
    }
    size_t offset = strlen(str1);
    for (size_t i = 0; i < std::strlen(str2); ++i) {
        p[i + offset] = str2[i];
    }

    for (size_t i = 0; i < std::strlen(str1) + std::strlen(str2); ++i) {
        std::cout << p[i];
    }
    std::cout << std::endl;
}

void func2() {
    const std::string str1 = "Hello, ";
    const std::string str2 = "World.";
    std::unique_ptr<char[]> p(new char[str1.length() + str2.length()]);
    for (size_t i = 0; i < str1.length(); ++i) {
        p[i] = str1[i];
    }
    size_t offset = str1.length();
    for (size_t i = 0; i < str2.length(); ++i) {
        p[i + offset] = str2[i];
    }

    for (size_t i = 0; i < str1.length() + str2.length(); ++i) {
        std::cout << p[i];
    }
    std::cout << std::endl;
}


int main(int argc, char const *argv[]) {
    func1();
    func2();
    return 0;
}
