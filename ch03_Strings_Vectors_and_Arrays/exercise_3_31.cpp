/*
 * 编写一段程序，定义一个含有10个int的数组，令每个元素的值就是其下标值。
 */

#include <iostream>
#include <vector>

int main(void) {
    int arr[10] = {};
    for (int i = 0; i < 10; ++i) {
        arr[i] = i;
    }
    for (int i = 0; i < 10; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
