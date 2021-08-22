/*
 * 修改你为1，4，1节练习1.10所编写的程序（打印一个范围内的数），使其处理用户输入的第一个数比第二数小的情况。
 */

#include <iostream>
int main(void) {
    int val1 = 0, val2 = 0;
    std::cout << "Enter two numbers: ";
    std::cin >> val1 >> val2;
    if (val1 > val2) {
        int tmp = val1;
        val1 = val2;
        val2 = tmp;
    }
    while (val1 <= val2) {
        std::cout << val1++ << " ";
    }
    std::cout << std::endl;
    return 0;
}
