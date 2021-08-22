/*
 * 改写上题的程序，不过这次读入的是字符。
 */

#include <iostream>
#include <string>
#include <vector>

int main(void) {
    std::string word;
    std::vector<std::string> svec;
    while (std::cin >> word) {
        svec.push_back(word);
    }
    for (const auto &i : svec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
