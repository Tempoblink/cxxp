/*
 * 假设i、j和k是三个整数，说明表达式i!=j<k的含义。
 */

/*
 * 先j<k的判断，再将判断其结果与i是否相等。
 */

#include <iostream>

int main(void) {
    int i = 1, j = 1, k = 2;
    std::cout << (i != j < k) << std::endl;
    return 0;
}
