/*
 * 编写你自己版本的print函数，并打印一个、两个及五个实参来测试它，要打印的每个实参都应有不同的类型。
 */

#include <iostream>

template<typename T>
std::ostream &print(std::ostream &os, const T &t) {
    return os << t;
}

template<typename T, typename... Args>
std::ostream &print(std::ostream &os, const T &t, const Args &...rest) {
    os << t << ", ";
    return print(os, rest...);
}


int main(int argc, char const *argv[]) {
    int i = 0;
    std::string s = "how now brown cow";
    print(std::cout, i, s, 42);
    return 0;
}
