/*
 * 编写一段程序，用整型数组初始化一个vector对象。
 */

#include <iostream>
#include <vector>

int main(void) {
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int>(std::begin(arr), std::end(arr));
    for (const auto &i : arr) {
      std::cout << i << " ";
    }
    std::cout <<std::endl;
    return 0;
}
