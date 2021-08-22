/*
 * 如何从一个list<int>初始化一个vector<double>？
 * 从一个vector<int>又该如何创建？编写代码验证你的答案。
 */

#include <iostream>
#include <list>
#include <vector>

void print(const std::vector<int> &ivec) {
    for (auto &i : ivec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void print(const std::list<int> &li) {
    for (auto &i : li) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}


int main(void) {
    std::list<int> li(10, 5);
    std::cout << "li\t = ";
    print(li);

    std::vector<int> ivec1(li.begin(), li.end());
    std::cout << "ivec1\t = ";
    print(ivec1);

    std::vector<int> ivec2(ivec1);
    std::cout << "ivec2\t = ";
    print(ivec2);

    return 0;
}
