/*
 * 编写一个函数，当它第一次调用时返回0，以后每次被调用返回值加1。
 */

#include <iostream>

int func() {
    static int num = 0;
    return num++;
}

int main(void) {
    std::cout << "1: " << func() << std::endl;
    std::cout << "2: " << func() << std::endl;
    std::cout << "3: " << func() << std::endl;
    std::cout << "4: " << func() << std::endl;
    std::cout << "5: " << func() << std::endl;
    return 0;
}
