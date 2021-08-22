/*
 * 定义一个函数模板，统计一个给定值在一个vector中出现的次数。
 * 测试你的函数，分别传递给它一个double的vector，
 * 一个int的vector以及一个string的vector。
 */

#include <iostream>
#include <string>
#include <vector>

template<typename T>
size_t cal_count(const T &num, const std::vector<T> v) {
    size_t i = 0;
    for (auto n : v)
        if (num == n)
            ++i;
    return i;
}


int main(int argc, char const *argv[]) {
    std::vector<int> ivec{1, 2, 2, 3, 2, 4, 2};
    std::cout << cal_count(2, ivec) << std::endl;
    std::vector<double> dvec{1.1, 2.2, 2.2, 2.3, 2.2};
    std::cout << cal_count(2.2, dvec) << std::endl;
    std::vector<std::string> svec{"c", "c", "c"};
    std::cout << cal_count(std::string("c"), svec) << std::endl;
    return 0;
}
