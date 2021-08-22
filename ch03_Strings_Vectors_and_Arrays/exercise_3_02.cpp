/*
 * 编写一段程序从标准输入中一次读入一整行。
 * 然后修改该程序使其一次读入一个词。
 */

#include <iostream>
#include <string>

int main(void) {
    /*
    std::string line;
    while (getline(std::cin, line)) {
        std::cout << line << std::endl;
    }
    */

    std::string word;
    while (std::cin >> word) {
        std::cout << word << std::endl;
    }
    return 0;
}
