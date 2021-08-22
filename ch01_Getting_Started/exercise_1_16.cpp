/*
 * 编写程序，从cin读取一组数，输出其和。
 */

#include <iostream>

int main(void) {
    int sum = 0, val = 0;
    while (std::cin >> val) {
        sum += val;
    }
    std::cout << "The sum is: " << sum << std::endl;
    return 0;
}
