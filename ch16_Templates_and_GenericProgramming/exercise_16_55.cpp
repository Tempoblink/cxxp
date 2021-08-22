/*
 * 练习16.55：如果我们的可变参数版本print的定义之后声明非可变阐述版本，
 * 解释可变参数的版本会如何执行。
 */

/*
 * 无限递归，最后到print(os); 然而并没有定义这个函数。
 */

#include <iostream>

std::ostream &print(std::ostream &os) {
    return os;
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
