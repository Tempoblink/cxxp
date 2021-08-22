/*
 * 写出一条表达式用于确定一个整数是奇数还是偶数。
 */

#include <iostream>

int main(void) {
    int num;
    std::cin >> num;
    if (num % 2 == 0) {
        std::cout << "偶数" << std::endl;
    } else {
        std::cout << "奇数" << std::endl;
    }
    return 0;
}
