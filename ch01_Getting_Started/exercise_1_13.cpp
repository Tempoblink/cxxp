/*
 *使用for循环重做1.4.1节的所有练习。
 */


#include <iostream>

int main(void) {
    //1.9
    int sum = 0;
    for (int i = 50; i <= 100; ++i) {
        sum += i;
    }
    std::cout << "The sum is: " << sum << std::endl;


    //1.10
    for (int i = 10; i >= 0; --i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    //1.11

    int val1 = 0, val2 = 0;
    std::cout << "Enter two numbers: ";
    std::cin >> val1 >> val2;
    for (; val1 <= val2; ++val1) {
        std::cout << val1 << " ";
    }
    std::cout << std::endl;
    return 0;
}
