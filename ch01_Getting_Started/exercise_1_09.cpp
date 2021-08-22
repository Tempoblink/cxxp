/*
 * 编写程序，使用while循环将50到100的整数相加。
 */

#include <iostream>

int main(void) {
    int sum = 0, val = 50;
    while (val < 101) {
        sum += val;
        ++val;
    }
    std::cout << "Sum of 50 to 100 inclusive is " << sum << std::endl;
    return 0;
}
