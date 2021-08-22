/*
 * 用accumulate求一个vector<int>中的元素之和。
 */

#include <iostream>
#include <numeric>
#include <vector>

int main(int argc, char const *argv[]) {
    std::vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "ivec = " << std::accumulate(ivec.cbegin(), ivec.cend(), 0)
              << std::endl;
    return 0;
}
