/*
 * 编写一段程序，从标准输入读取两个整数，输出第一个数除以第二个数的结果。
 */

#include <iostream>

int main(void) {
    int val1, val2;
    std::cout << "Enter two numbers: ";
    std::cin >> val1 >> val2;
    std::cout << static_cast<double>(val1) / val2 << std::endl;
    return 0;
}
