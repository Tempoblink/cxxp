/*
 * 重写上题的程序，用list替代deque。列出程序要做出哪些改变。
 */

#include <list>
#include <iostream>
#include <string>

int main(void) {
    std::string word;
    std::list<std::string> sdeq;
    while (std::cin >> word) {
        sdeq.push_back(word);
    }
    for (const auto &i : sdeq) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
