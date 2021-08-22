/*
 * 书写一条表达式用于测试4个值a、b、c、d的关系，确保a大于b、b大于c、c大于d。
 */

#include <iostream>

int main(void) {
    int a = 4, b = 3, c = 2, d = 1;
    if (a > b && b > c && c > d) {
        std::cout << "a > b, b > c, c > d" << std::endl;
    } else {
        std::cout << "Not a b c d" << std::endl;
    }
    return 0;
}
