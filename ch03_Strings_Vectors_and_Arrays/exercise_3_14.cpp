/*
 * 编写一段程序，用cin读入一组整数并把它们存入一个vector对象。
 */

#include <iostream>
#include <vector>

int main(void) {
    int num;
    std::vector<int> ivec;
    while (std::cin >> num) {
        ivec.push_back(num);
    }
    for (auto i : ivec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
