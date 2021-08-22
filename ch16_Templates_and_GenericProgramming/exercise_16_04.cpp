/*
 * 编写行为类似标准库find算法的模板。
 * 函数需要两个模板类型参数，一个表示函数的迭代器参数，另一个表示值的类型。
 * 使用你的函数在一个vector<int>和一个list<string>中查找给定值。
 */


#include <vector>
#include <list>
#include <string>
#include <iostream>

template<typename iter, typename value>
iter find(iter &start, iter &end, const value &v) {
    while (start != end) {
        if (*start == v)
            return start;
        ++start;
    }
    return start;
}

int main(int argc, char const *argv[]) {
    std::vector<int> ivec{1, 2, 3, 4, 5, 6, 7};
    auto r1 = find(ivec.begin(), ivec.end(), 5);
    std::list<std::string> slist{"Hello", "Hi", "Hey"};
    auto r2 = find(slist.begin(), slist.end(), "Hi");
    std::cout << *r1 << std::endl;
    std::cout << *r2 << std::endl;
    return 0;
}
