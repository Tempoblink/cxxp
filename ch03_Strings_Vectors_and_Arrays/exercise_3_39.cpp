/*
 * 编写一段程序，比较两个string对象。再编写一段程序，比较两个C风格字符串的内容。
 */

#include <cstring>
#include <iostream>
#include <string>

int main(void) {
    std::string str1("Good day!");
    std::string str2("Have fun!");

    if (str1 == str2) {
        std::cout << "str1 == str2" << std::endl;
    } else if (str1 < str2) {
        std::cout << "str1 < str2" << std::endl;
    } else {
        std::cout << "str1 > str2" << std::endl;
    }

    char cstr1[] = "Good day!";
    char cstr2[] = "Have fun!";
    auto res = strcmp(cstr1, cstr2);
    if (res == 0) {
        std::cout << "cstr1 == cstr2" << std::endl;
    } else if (res > 0) {
        std::cout << "cstr1 > cstr2" << std::endl;
    } else {
        std::cout << "cstr1 < cstr2" << std::endl;
    }

    return 0;
}
