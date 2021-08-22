/*
 * 使用你为8.1.2节（第281页）第一个练习所编写的函数打印一个istringstream对象的内容。
 */


#include <iostream>
#include <sstream>
#include <string>

std::istream &func(std::istringstream &is) {
    std::string word;
    while (is >> word)
        std::cout << word << "+ ";
    std::cout << std::endl;
    return is;
}

int main(void) {
    std::string line;
    while (getline(std::cin, line)) {
        std::istringstream record(line);
        func(record);
    }
    return 0;
}
