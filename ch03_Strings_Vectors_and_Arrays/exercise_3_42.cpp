/*
 * 编写一段程序，将含有整数元素的vector对象拷贝给一个整型数组。
 */

#include <iostream>
#include <vector>

int main(void) {
    std::vector<int> ivec(10,1);
    int arr[ivec.size()];
    int *p = arr;
    for (const auto &i : ivec) {
      *p = i;
      ++p;
    }
    for (const auto &i : arr) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
