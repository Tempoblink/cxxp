/*
 * 使用标准库函数对象及适配器定义一条表达式，令其
 * (a) 统计大于1024的值有多少个。
 * (b) 找到第一个不等于pooh的字符串。
 * (c) 将所有的值乘以2。
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
    std::vector<int> ivec1{1025, 1026, 1027, 1021, 1023};
    std::vector<std::string> svec{"pooh", "booh", "pooh"};
    std::vector<int> ivec2{1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto adapter1 = std::bind(std::greater<int>(), std::placeholders::_1, 1024);
    auto count_result = std::count_if(ivec1.begin(), ivec1.end(), adapter1);

    auto adapter2 = std::bind(std::not_equal_to<std::string>(), std::placeholders::_1, "pooh");
    auto nopooh = std::find_if(svec.begin(), svec.end(), adapter2);

    auto adapter3 = std::bind(std::multiplies<int>(), std::placeholders::_1, 2);
    std::transform(ivec2.begin(), ivec2.end(), ivec2.begin(), adapter3);


    std::cout << count_result << std::endl;
    std::cout << *nopooh << std::endl;
    std::for_each(ivec2.begin(), ivec2.end(), [](const int &i) { std::cout << i << " "; });
    std::cout << std::endl;
    return 0;
}
