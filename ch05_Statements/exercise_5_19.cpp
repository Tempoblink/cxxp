/*
 * 编写一段程序，使用do while循环重复地执行下述任务：
 * 首先提示用户输入两个string对象，然后挑出较短的那个并输出它。
 */

#include <iostream>
#include <string>

int main(void) {
    std::string str1, str2;
    do {
        std::cout << "Enter two strings: ";
        if (std::cin >> str1 >> str2) {
            if (str1.size() < str2.size())
                std::cout << str1 << " is the shorter." << std::endl;
            else
                std::cout << str2 << " is the shorter." << std::endl;
        }
    } while (std::cin);
    return 0;
}
