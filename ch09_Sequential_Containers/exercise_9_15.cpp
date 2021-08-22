/*
 * 编写程序，判定两个vector<int>是否相等。
 */

#include <iostream>
#include <vector>

int main(void) {
    std::vector<int> ivec1(10);
    std::vector<int> ivec2(9);
    std::vector<int> ivec3(10, 1);
    std::vector<int> ivec4{1, 2, 3, 4, 5};

    std::cout << "ivec1(10) "
              << (ivec1 < ivec2 ? '<' : '>')
              << " ivec2(9)"
              << std::endl;
    std::cout << "ivec2(9) "
              << (ivec2 < ivec3 ? '<' : '>')
              << " ivec3(10,1)"
              << std::endl;
    std::cout << "ivec1(10) "
              << (ivec1 < ivec3 ? '<' : '>')
              << " ivec3(10,1)"
              << std::endl;
    std::cout << "ivec3(10,1) "
              << (ivec3 < ivec4 ? '<' : '>')
              << " ivec4{1,2,3,4,5}"
              << std::endl;

    return 0;
}
