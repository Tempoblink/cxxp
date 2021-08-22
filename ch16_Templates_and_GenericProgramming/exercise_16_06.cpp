/*
 * 你认为接受一个数组实参的标准库函数begin和end是如何工作的？
 * 定义你自己版本的begin和end。
 */

#include <iostream>

template<typename T, unsigned N>
T *begin(T (&arr)[N]) {
    return arr;
}
template<typename T, unsigned N>
T *end(T (&arr)[N]) {
    return arr + N;
}

int main(int argc, char const *argv[]) {
    int k[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "begin(k) = " << reinterpret_cast<long>(begin(k)) << std::endl;
    std::cout << "end(k) = " << reinterpret_cast<long>(end(k)) << std::endl;
    std::cout << "count(k) = " << reinterpret_cast<long>(end(k) - begin(k)) << std::endl;
    std::cout << "begin(k) = " << *begin(k) << std::endl;
    std::cout << "end(k) = " << *(end(k) - 1) << std::endl;

    char c[] = {'a', 'b', 'c', 'd'};
    std::cout << "begin(c) = " << reinterpret_cast<std::int_fast64_t>(begin(c)) << std::endl;
    std::cout << "end(c) = " << reinterpret_cast<std::int_fast64_t>(end(c)) << std::endl;
    std::cout << "count(c) = " << ((end(c) - begin(c))) << std::endl;
    std::cout << "*begin(c) = " << *begin(c) << std::endl;
    std::cout << "*end(c) = " << *(end(c) - 1) << std::endl;
    return 0;
}
