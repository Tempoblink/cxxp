/*
 * 测试函数，调用参数为cin。
 */

#include <iostream>
#include <string>

std::istream &func(std::istream &is) {
    std::string word;
    while (is >> word)
        std::cout << word << " ";
    std::cout << std::endl;
    is.clear();
    return is;
}

int main(void) {
    func(std::cin);
    return 0;
}
