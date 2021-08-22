/*
 * 头文件algorithm中定义了一个名为count的函数，它类似find，接受一对迭代器和一个值作为参数。
 * count返回给定值在序列中出现的次数。
 * 编写程序，读取int序列存入vector中，打印有多少个元素的值等于给定值。
 */

#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
    std::vector<int> ivec{1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    auto time = std::count(ivec.begin(), ivec.end(), 2);
    std::cout << "2 has occour " << time << " time" << (time > 1 ? "s" : "")
              << std::endl;

    return 0;
}
