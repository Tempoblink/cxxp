/*
 * 参考本节介绍的几个print函数，根据理解编写你自己的版本。
 * 以此调用每个函数使其输入下面定义的i和j。
 * int i = 0, j[2] = {0, 1};
 */

#include <iostream>
#include <string>

void print(const char *cp) {
    if (cp) {
        while (*cp)
            std::cout << *cp++;
        std::cout << std::endl;
    }
}

void print(const int *beg, const int *end) {
    while (beg != end)
        std::cout << *beg++ << " ";
    std::cout << std::endl;
}

void print(const int ia[], size_t size) {
    for (size_t i = 0; i < size; ++i)
        std::cout << ia[i] << " ";
    std::cout << std::endl;
}
int main(void) {
    int i = 0, j[2] = {0, 1};
    print(std::begin(j), std::end(j));
    print(&i, 1);

    std::string str("Hello, World");
    print(str.c_str());
    const char q[] = "hELLO,wORLD\0";
    print(q);

    return 0;
}
