/*
 * 为6种创建和初始化vector对象的方法，每一种都给出一个实例。
 * 解释每个vector包含什么值。
 */

#include <iostream>
#include <vector>

void print(const std::vector<int> &ivec) {
    for (auto &i : ivec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}


int main(void) {
    std::vector<int> ivec1;
    std::cout << "ivec1 = ";
    print(ivec1);

    std::vector<int> ivec2(ivec1);
    std::cout << "ivec2 = ";
    print(ivec2);

    std::vector<int> ivec3{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "ivec3 = ";
    print(ivec3);

    std::vector<int> ivec4 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "ivec4 = ";
    print(ivec4);

    std::vector<int> ivec5(ivec4.begin(), ivec4.end());
    std::cout << "ivec5 = ";
    print(ivec5);

    std::vector<int> ivec6(9);
    std::cout << "ivec6 = ";
    print(ivec6);

    std::vector<int> ivec7(9, 1);
    std::cout << "ivec7 = ";
    print(ivec7);

    return 0;
}
