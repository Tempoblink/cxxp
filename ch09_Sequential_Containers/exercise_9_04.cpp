/*
 * 编写函数，接受一对指向vector<int>的迭代器和一个int值。
 * 在两个迭代器指定的范围中查找给定的值，返回一个布尔值来指出是否找到。
 */

#include <iostream>
#include <vector>
using it = std::vector<int>::iterator;

bool find_it(it a, it b, int i) {
    if (a - b > 0) find_it(b, a, i);
    while (a != b) {
        if (*a++ == i) return true;
    }
    return false;
}

int main(void) {
    std::vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    it start = ivec.begin();
    it end = ivec.end();
    std::cout << "Is 5 in the box? " << std::boolalpha << find_it(start, end, 5) << std::endl;
    return 0;
}
