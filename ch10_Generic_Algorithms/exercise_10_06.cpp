/*
 * 编写程序，使用fill_n将一个序列中的int值都设置为0。
 */

#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
    std::vector<int> ivec(10, 1);
    std::fill_n(ivec.begin(), 10, 0);
    for (const auto &i : ivec)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}
