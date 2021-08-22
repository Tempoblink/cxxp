/*
 * 将上一题刚刚创建的数组拷贝给另外一个数组。利用vector重写程序，实现类似的功能。
 */

#include <iostream>
#include <vector>

int main(void) {
    std::vector<int> ivec;
    for (int i = 0; i < 10; ++i) {
        ivec.push_back(i);
    }
    for (const auto &i : ivec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
