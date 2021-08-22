/*
 * 对于104页的程序来说，如果不初始化scores将发生什么？
 */

/*
 * scores数组里的元素将拥有未定义的值，导致计算结果未知。
 */


#include <iostream>
#include <vector>

int main(void) {
    unsigned scores[11] = {};
    unsigned grade;
    while (std::cin >> grade) {
        if (grade <= 100)
            ++scores[grade / 10];
    }
    /*
    *for (int i = 0; i < 11; ++i) {
    *    std::cout << scores[i] << " ";
    *}
    *std::cout << std::endl;
    */
    for (const auto &i : scores) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
