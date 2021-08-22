/*
 * 编写一段程序，使用条件运算符从vector<int>中找到哪些元素的值是奇数，然后将这些奇数值翻倍。
 */

#include <iostream>
#include <vector>

int main(void) {
    std::vector<int> ivec{1, 2, 3, 4, 5, 6};
    for (auto &i : ivec) {
        if (i % 2 != 0)
            i *= i;
    }
    for (const auto &i : ivec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
