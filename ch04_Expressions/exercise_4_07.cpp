/*
 * 溢出是何含义？写出三条导致溢出的表达式。
 */

/*
 * 当计算的结果超出该类型所能表示的范围时就会产生溢出。
 */

#include <iostream>
#include <limits>

int main(void) {
    short st = SHRT_MAX + 1;
    std::cout << "short st = " << st << std::endl;

    unsigned ui = -1;
    std::cout << "unsigned ui = " << ui << std::endl;

    char c = CHAR_MAX + 1;
    std::cout << "char c = " << static_cast<int>(c) << std::endl;

    return 0;
}
