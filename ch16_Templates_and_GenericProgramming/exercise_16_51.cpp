/*
 * 调用本节中的每个foo，确定sizeof...(Args)和sizeof...(rest)分别返回什么。
 */

#include <iostream>
#include <string>

template<typename T, typename... Args>
void foo(const T &t, const Args &...rest) {
    std::cout << sizeof...(Args) << std::endl;
    std::cout << sizeof...(rest) << std::endl;
}

int main(int argc, char const *argv[]) {
    int i = 0;
    double d = 3.14;
    std::string s = "how now brown cow";
    foo(i, s, 42, d);
    foo(s, 42, "hi");
    foo(d, s);
    foo("hi");
    return 0;
}