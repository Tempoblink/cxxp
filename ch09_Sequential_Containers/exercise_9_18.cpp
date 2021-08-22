/*
 * 编写程序，从标准输入读取string序列，存入一个deque中。
 * 编写一个循环，用迭代器打印deque中的元素。
 */

#include <deque>
#include <iostream>
#include <string>

int main(void) {
    std::string word;
    std::deque<std::string> sdeq;
    while (std::cin >> word) {
        sdeq.push_back(word);
    }
    for (const auto &i : sdeq) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
