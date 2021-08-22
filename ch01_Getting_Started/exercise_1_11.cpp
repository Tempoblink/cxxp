/*
 * 编写程序，提示用户输入两个整数，打印出这两个整数所指定的范围内的所有整数。
 */

#include <iostream>

int main(void) {
    int val1 = 0, val2 = 0;
    std::cout << "Enter two numbers: ";
    std::cin >> val1 >> val2;
    std::cout << "The " << val1 << " to " << val2 << " have: ";
    while (val1 <= val2) {
        std::cout << val1 << " ";
        ++val1;
    }
    std::cout << std::endl;
    return 0;
}
