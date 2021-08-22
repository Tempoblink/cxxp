/*
 * 从cin读入一组词并把它们存入一个vector对象，然后设法把所有词都改为大写形式。
 * 输出改变后的结果，每个词占一行。
 */

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

int main(void) {
    std::string word;
    std::vector<std::string> svec;
    while (std::cin >> word) {
        svec.push_back(word);
    }
    for (auto &w : svec) {
        for (auto &i : w) {
            i = toupper(i);
        }
    }
    for (const auto & word: svec) {
      std::cout << word << std::endl;
    }
    return 0;
}
