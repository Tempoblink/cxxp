/*
 * 请使用迭代器重做3.3.3节（第94页）的最后一个练习。
 */

#include <iostream>
#include <vector>

int main(void) {
    std::vector<int> ivec;
    int num;

    std::cout << "Enter some numbers: ";
    while (std::cin >> num) {
        ivec.push_back(num);
    }

    //1
    for (auto it = ivec.begin() + 1; it != ivec.end(); ++it) {
        std::cout << *(it - 1) + *it << " ";
    }
    std::cout << std::endl;

    //2
    for (auto it1 = ivec.begin(), it2 = ivec.end() - 1; it1 != it2; ++it1, --it2) {
        std::cout << *it1 + *it2 << " ";
    }
    std::cout << std::endl;
    return 0;
}
