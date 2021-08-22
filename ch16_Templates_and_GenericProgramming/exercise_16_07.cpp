/*
 * 编写一个constexpr模板，返回给定数组的大小。
 */

#include <iostream>

template<typename T, unsigned N>
constexpr unsigned count_arr(T (&arr)[N]) {
    return N;
}

int main(int argc, char const *argv[]) {
    int k[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << count_arr(k) << std::endl;
    return 0;
}
