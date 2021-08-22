/*
 * 编写程序，分别使用at、下标运算符、front和begin提取一个vector中的第一个元素。
 * 在一个空的vector上测试你的程序。
 */

#include <iostream>
#include <vector>

int main(void) {
    std::vector<int> ivec{1,2,3};
    using size_type = std::vector<int>::size_type;
    std::cout << "ivec.at(0)\t = "
              << ivec.at(static_cast<size_type>(0))
              << std::endl;
    std::cout << "ivec[0]\t = "
              << ivec[0]
              << std::endl;
    std::cout << "ivec.front()\t = "
              << ivec.front()
              << std::endl;
    std::cout << "ivec.begin()\t = "
              << *ivec.begin()
              << std::endl;
    return 0;
}
