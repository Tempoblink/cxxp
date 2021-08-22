/*
 * 编写一个函数，它的参数是initializer_list<int>类型的对象，
 * 函数的功能是计算列表中所有元素的和。
 */

#include <initializer_list>
#include <iostream>

int func(std::initializer_list<int> li) {
    int sum = 0;
    for (const auto &i : li) {
        sum += i;
    }
    return sum;
}

int main(void) {
    int sum = func({1, 2, 3, 4, 5, 6, 7, 8, 9});
    std::cout << "sum = " << sum << std::endl;
    return 0;
}
