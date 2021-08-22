/*
 * 使用reverse_iterator逆序打印一个vector。
 */

#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
    std::vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "reverse ivec = ";
    for (auto iter = ivec.crbegin(); iter != ivec.crend(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    return 0;
}
