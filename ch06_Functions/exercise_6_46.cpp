/*
 * 能把isShorter函数定义成constexpr函数吗？
 * 如果能，将他改写成constexpr函数；如果不能，说明原因。
 */

/*
 * https://github.com/ReadingLab/Discussion-for-Cpp/issues/22#issuecomment-234237144
 */

#include <iostream>
#include <string>

constexpr bool isShorter(const std::string &s1, const std::string &s2) {
    return s1.size() < s2.size();
}

int main(void) {
    std::cout << isShorter("Hello", "World") << std::endl;
    return 0;
}
