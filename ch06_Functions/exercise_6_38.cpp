/*
 * 修改arrPtr函数，使其返回数组的引用。
 */

#include <iostream>

int odd[] = {1, 3, 5, 7, 9};
int even[] = {2, 4, 6, 8, 10};

decltype(odd) &arrRefe(int i) {
    return (i % 2) ? odd : even;
}

int main(void) {
    for (const auto &var : arrRefe(5)) {
        std::cout << var << " ";
    }
    std::cout << std::endl;
    return 0;
}
