/*
 * 为while循环写一个条件，使其从标准输入中读取整数，遇到42时停止。
 */

#include <iostream>

int main(void) {
    int num;
    while (std::cin >> num && num != 42)
        std::cout << "It's not 42!" << std::endl;
    return 0;
}
