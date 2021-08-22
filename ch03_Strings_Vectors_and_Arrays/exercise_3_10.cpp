/*
 * 编写一段程序，读入一个包含标点符号的字符串，将标点符号去除后输出字符串剩余的部分。
 */


#include <cctype>
#include <iostream>
#include <string>

int main(void) {
    std::string str;
    std::cout << "Enter a string: ";
    getline(std::cin, str);
    for (const auto &var : str) {
        if (!ispunct(var)) {
            std::cout << var;
        }
    }
    std::cout << std::endl;

    return 0;
}
