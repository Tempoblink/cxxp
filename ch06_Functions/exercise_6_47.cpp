/*
 * 改写6.3.2节（第205页）练习中使用递归输出vector内容的程序，使其有条件地输出与执行过程有关的信息。
 * 例如，每次调用时输出vector对象的大小。分别在打开和关闭调试器的情况下编译并执行这个程序。
 */


#include <iostream>
#include <vector>

//#define NDEBUG

void print(std::vector<int>::iterator &it) {
    if (!*it) {
        std::cout << std::endl;
        return;
    }
    std::cout << *it << " ";
#ifndef NDEBUG
    std::cout << "sizeof(*it) : " << sizeof(*it) << std::endl;
#endif

    print(++it);
}

int main(void) {
    std::vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto p = ivec.begin();
    print(p);
    return 0;
}
