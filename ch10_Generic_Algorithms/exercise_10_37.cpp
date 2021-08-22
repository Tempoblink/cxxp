/*
 * 给定一个包含10个元素的vector，
 * 将位置3到7之间的元素按逆序拷贝到一个list中。
 */

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

int main(int argc, char const *argv[]) {
    std::vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<int> ilist(ivec.crbegin() + 2, ivec.crend() - 3);
    for (const auto &i : ilist)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}
