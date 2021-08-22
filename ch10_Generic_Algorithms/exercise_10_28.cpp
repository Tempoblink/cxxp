/*
 * 一个vector中保存1到9，将其拷贝到三个其他容器中。
 * 分别使用inserter、back_inserter和front_inserter将元素添加到三个容器中。
 * 对每种inserter，估计输出序列是怎样的，运行程序验证你的估计是否正确。
 */

#include <deque>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

int main(int argc, char const *argv[]) {
    std::vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};

    //1
    std::vector<int> ivec2;
    std::copy(ivec.begin(), ivec.end(), std::back_inserter(ivec2));
    std::cout << "vector<int>   back_inserter" << std::endl;
    for (const auto &i : ivec2)
        std::cout << i << " ";
    std::cout << std::endl;

    //2
    std::list<int> ilist;
    std::copy(ivec.begin(), ivec.end(), std::front_inserter(ilist));
    std::cout << "list<int>   front_inserter" << std::endl;
    for (const auto &i : ilist)
        std::cout << i << " ";
    std::cout << std::endl;

    //3
    std::deque<int> ideq;
    std::copy(ivec.begin(), ivec.end(), std::inserter(ideq, ideq.begin()));
    std::cout << "deque<int>   inserter" << std::endl;
    for (const auto &i : ideq)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
