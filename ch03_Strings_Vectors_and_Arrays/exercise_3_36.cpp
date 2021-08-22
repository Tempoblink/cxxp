/*
 * 写一段程序，比较两个数组是否相等，再写一段程序，比较两个vector对象是否相等。
 */

#include <iostream>
#include <vector>

int main(void) {
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {1, 2, 3, 4, 5};
    int arr3[5] = {0, 0, 0, 0, 0};
    int i = 0;
    //1.1相等
    for (; i < 5; ++i) {
        if (arr1[i] != arr2[i])
            break;
    }
    if (i == 5) {
        std::cout << "There are same." << std::endl;
    } else {
        std::cout << "There are not same." << std::endl;
    }
    //1.2不相等
    for (i = 0; i < 5; ++i) {
        if (arr1[i] != arr3[i])
            break;
    }
    if (i == 5) {
        std::cout << "There are same." << std::endl;
    } else {
        std::cout << "There are not same." << std::endl;
    }


    //2.1
    std::vector<int> ivec1{1, 2, 3, 4, 5};
    std::vector<int> ivec2{1, 2, 3, 4, 5};
    std::vector<int> ivec3{0, 0, 0, 0, 0};
    auto it1 = ivec1.begin(), it2 = ivec2.begin(), it3 = ivec3.begin();
    for (; it1 != ivec1.end() && it2 != ivec2.end(); ++it1, ++it2) {
        if (*it1 != *it2)
            break;
    }

    if (it1 == ivec1.end() && it2 == ivec2.end()) {
        std::cout << "There are same." << std::endl;
    } else {
        std::cout << "There are not same." << std::endl;
    }

    //2.2
    for (; it1 != ivec1.end() && it3 != ivec3.end(); ++it1, ++it3) {
        if (*it1 != *it2)
            break;
    }

    if (it1 == ivec1.end() && it3 == ivec3.end()) {
        std::cout << "There are same." << std::endl;
    } else {
        std::cout << "There are not same." << std::endl;
    }
    return 0;
}
