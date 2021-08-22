/*
 * 编写一个递归函数，输出vector对象的内容。
 */

#include <iostream>
#include <vector>

void print(std::vector<int>::iterator &it) {
    if (!*it) {
        std::cout << std::endl;
        return;
    }
    std::cout << *it << " ";
    print(++it);
}

int main(void) {
    std::vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto p = ivec.begin();
    print(p);
    return 0;
}
