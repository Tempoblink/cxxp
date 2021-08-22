/*
 * 除了unique（参见10.2.3节，第343页）之外，
 * 标准库还定义了名为unique_copy的函数，
 * 它接受第三个迭代器，表示拷贝不重复元素的目的位置。
 * 编写一个程序，使用unique_copy将一个vector中不重复的元素拷贝到一个初始为空的list中。
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

int main(int argc, char const *argv[]) {
    std::vector<int> ivec{1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 6, 6, 6, 6};
    std::list<int> ilist;
    std::unique_copy(ivec.begin(), ivec.end(), std::back_inserter(ilist));
    for (const auto &i : ilist)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}
