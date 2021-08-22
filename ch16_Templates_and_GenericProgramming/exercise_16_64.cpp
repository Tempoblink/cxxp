/*
 * 为上一题中的模板编写特例化版本来处理vector<const char*>。编写程序使用这个特例化的版本。
 */

#include <cstring>
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

template<>
size_t cal_count(const char *const &num, const std::vector<const char *> v) {
    size_t i = 0;
    for (auto n : v)
        if (strcmp(num, n) == 0)
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
    std::vector<const char *> cvec{"and", "and"};
    std::cout << cal_count((const char *) "and", cvec) << std::endl;
    return 0;
}
