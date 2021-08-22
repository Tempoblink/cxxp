/*
 * 假设有两个包含整数的vector对象，编写一段程序，检验其中一个vector对象是否是另一个的前缀。
 * 为了实现这一目标，对于两个不等长的vector对象，只需挑出长度较短的那个，把它的所有元素和另一个vector对象比较即可。
 * 例如，如果两个vector对象的元素分别是0, 1, 1, 2和0, 1, 1, 2, 3, 5, 8，则程序返回的结果应该为真。
 */

#include <iostream>
#include <vector>

int main(void) {
    std::vector<int> ivec1{0, 1, 1, 2, 3, 5, 8};
    std::vector<int> ivec2{0, 1, 1};
    auto it1 = ivec1.cbegin(), it2 = ivec2.cbegin();
    for (; it1 != ivec1.cend() && it2 != ivec2.cend(); ++it1, ++it2) {
        if (*it1 != *it2) break;
    }

    if (it1 == ivec1.end() || it2 == ivec2.end()) {
        std::cout << "Ture" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }
    return 0;
}
