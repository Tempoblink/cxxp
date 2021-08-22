/*
 * 重写上一题的函数，返回一个迭代器指向找到的元素。
 * 注意，程序必须处理未找到给定值的情况。
 */


#include <iostream>
#include <vector>
using it = std::vector<int>::iterator;

it find_it(it a, it b, int i) {
    if (a - b > 0) find_it(b, a, i);
    while (a != b) {
        if (*a == i) return a;
        ++a;
    }
    return b + 1;
}

int main(void) {
    std::vector<int> ivec{1, 9, 5, 2, 4, 8, 7, 6};
    it start = ivec.begin();
    it end = ivec.end();
    it result = find_it(start, end, 5);
    std::cout << "5 is in the box? ";
    if (result != (end < start ? start : end) + 1) {
        std::cout << "true, It at " << (result - ivec.begin() + 1) << " site " << std::endl;
    } else {
        std::cout << "falsr." << std::endl;
    }
    return 0;
}
