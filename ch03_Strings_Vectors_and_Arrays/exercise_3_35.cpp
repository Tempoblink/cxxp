/*
 * 编写一段程序，利用指针将数组中的元素置为0.
 */

#include <iostream>

int main(void) {
    int arr[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    /*
    *for (int *i = arr; i != arr + 5; ++i) {
    *    *i = 0;
    *}
    *for (int i = 0; i < 5; ++i) {
    *    std::cout << arr[i] << " ";
    *}
    *std::cout << std::endl;
    */

    for (auto &i : arr) {
        i = 0;
    }
    for (const auto &i : arr) {
       std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
