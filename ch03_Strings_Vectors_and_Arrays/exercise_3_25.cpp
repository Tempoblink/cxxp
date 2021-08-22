/*
 * 3.3.3节划分分数段的程序是使用下标运算符实现的，请利用迭代器改写该程序并实现完全相同的功能。
 */

#include <iostream>
#include <vector>

int main(void) {
    std::vector<unsigned> scores(11, 0);
    unsigned grade;
    while (std::cin >> grade) {
        if (grade <= 100) {
            ++*(scores.begin() + grade / 10);
        }
    }
    for (auto it = scores.cbegin(); it != scores.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}
