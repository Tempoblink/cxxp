/*
 * 编写你自己的fact函数，上机检查是否正确。
 */

#include <iostream>

int fact(int val) {
    int ret = 1;
    for (; val > 1; --val) {
        ret *= val;
    }
    return ret;
}

int main(void) {
    int num = 0;
    std::cout << "Enter a number: ";
    std::cin >> num;
    std::cout << num << "! is " << fact(num) << std::endl;
    return 0;
}
