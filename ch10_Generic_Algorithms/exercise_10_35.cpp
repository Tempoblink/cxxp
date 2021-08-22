/*
 * 使用普通迭代器逆序打印一个vector。
 */

#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
    std::vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = ivec.cend();
    while (iter != ivec.cbegin())
        std::cout << *--iter << " ";
    std::cout << std::endl;
    return 0;
}
