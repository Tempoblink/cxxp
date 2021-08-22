/*
 * 编写一个函数，判断string对象中是否含有大写字母。
 * 编写另一个函数，把string对象全部改成小写形式。
 * 在这两个函数中你使用的形参类型相同吗？为什么？
 */

#include <iostream>
#include <string>

bool hasUpper(const std::string &str) {
    for (auto &ch : str)
        if (isupper(ch)) return true;
    return false;
}

void toLower(std::string &str) {
    for (auto &ch : str)
        if (isupper(ch))
            ch = tolower(ch);
}

int main(void) {
    std::string str = "hello, World!";
    std::cout << str << " has upper char? " << (hasUpper(str) ? "true" : "false") << std::endl;
    toLower(str);
    std::cout << "After toLower: " << str << std::endl;
    return 0;
}
