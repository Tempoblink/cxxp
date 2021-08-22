/*
 * 重写上一题的函数，使用begin和end返回的迭代器来控制循环。
 */

#include <iostream>
#include <iterator>
#include <vector>

template<typename container>
void print_container(const container &c) {
    for (auto begin = c.begin(); begin != c.end(); ++begin)
        std::cout << *begin << " ";
    std::cout << std::endl;
}

int main(int argc, char const *argv[]) {
    std::vector<int> ivec{1, 2, 3, 4, 5};
    print_container(ivec);
    return 0;
}
