/*
 * 将6.2.2节（第189页）的isShorter函数改写成内联函数。
 */

#include <iostream>
#include <string>

inline bool isShorter(const std::string &s1, const std::string &s2) {
    return s1.size() < s2.size();
}

int main(void) {
    std::cout << isShorter("Hello", "World") << std::endl;
    return 0;
}
