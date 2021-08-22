/*
 * 使用标准库函数对象判断一个给定的int值是否能被int容器中的所有元素整除。
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
    std::vector<int> ivec{2, 2, 2, 2, 2, 2, 2, 2};
    int i;
    std::cin >> i;
    auto adapter1 = std::bind(std::modulus<int>(), std::placeholders::_1, i);
    auto adapter2 = std::bind(std::equal_to<int>(), adapter1, 0);
    auto result = std::find_if_not(ivec.begin(), ivec.end(), adapter2);
    std::cout << std::boolalpha << (result == ivec.end()) << std::endl;
    return 0;
}
