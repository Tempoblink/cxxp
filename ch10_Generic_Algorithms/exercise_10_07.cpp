/*
 * 下面程序是否有错误？如果有，请改正。
 *
 * (a)
 * vector<int> vec; list<int> lst; int i;
 * while (cin >> i)
 *   lst.push_back(i);
 *   copy(lst.cbegin(), lst.cend(), vec.begin());
 *
 * (b)
 * vector<int> vec;
 * vec.reserve(10);
 * fill_n(vec.begin(), 10, 0);
 */

/*
 * vec为空，无法容量数据。要么初始化时静态声明空间：vector<int> vec(1024);
 *                        要么使用插入迭代器  back_inserter(vec);
 *
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

int main(int argc, char const *argv[]) {
    std::vector<int> vec;
    std::list<int> lst;
    int i;
    while (std::cin >> i) {
        lst.push_back(i);
    }
    std::copy(lst.cbegin(), lst.cend(), std::back_inserter(vec));

    for (const auto &i : vec)
        std::cout << i << " ";
    std::cout << std::endl;

    std::vector<int> avec;
    std::fill_n(std::back_inserter(avec), 10, 0);
    for (const auto &i : avec)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}
