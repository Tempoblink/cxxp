/*
 * 如果想定义一个含有10个元素的vector对象，所有元素的值都是42，
 * 请列举出三种不同的实现方法。哪种方法更好呢？为什么？
 */

#include <iostream>
#include <vector>

int main(void) {
    std::vector<int> ievc1(10, 42);
    std::vector<int> ievc2{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
    std::vector<int> ievc3;
    for (int i = 0; i < 10; ++i) {
        ievc3.push_back(42);
    }

    for (const auto &i : ievc1) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (const auto &i : ievc2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (const auto &i : ievc3) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
