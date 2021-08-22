/*
 * 编写并测试你自己版本的compare函数。
 */

#include <iostream>

template<typename T>
int compare(const T &v1, const T &v2) {
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}


int main(int argc, char const *argv[]) {
    std::cout << compare(2, 3) << std::endl;
    return 0;
}
