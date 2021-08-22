/*
 * 编写你自己版本的翻转函数，
 * 通过调用接受左值和右值引用参数的函数来测试它。
 */

#include <iostream>
#include <type_traits>
#include <utility>

template<typename F, typename T1, typename T2>
void fliq(F f, T1 &&t1, T2 &&t2) {
    f(t2, t1);
}

template<typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2) {
    f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void test(int &&t1, int &t2) {
    t2 = std::move(t1);
    std::cout << t2 << std::endl;
    std::cout << &t1 << std::endl;
    std::cout << &t2 << std::endl;
}

int main(int argc, char const *argv[]) {
    int i = 40;
    flip(test, i, 42);
    std::cout << &i << std::endl;
    // i 为左值， T1 -> int & 则 t1 为int &
    // 42为右值， T2 -> int   则 t2 为int &&
    //
    return 0;
}
