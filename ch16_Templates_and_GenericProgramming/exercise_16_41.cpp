/*
 * 编写一个新的sum版本，它的返回类型保证足够大，足以容纳加法的结果。
 */

#include <climits>
#include <iostream>
#include <type_traits>

template<typename T>
auto sum(const T &v1, const T &v2) -> decltype(v1 + v2) {
    return v1 + v2;
}

int main(int argc, char const *argv[]) {
    short a = SHRT_MAX;
    auto b = sum(a, a);
    std::cout << b << std::endl;
    std::cout << sizeof(a) << std::endl;
    std::cout << sizeof(b) << std::endl;
    return 0;
}
