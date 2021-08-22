/*
 * 对两个Sales_data对象调用你的compare函数，
 * 观察编译器在实例化过程中如何处理错误。
 */

#include <iostream>

template<typename T>
int compare(const T &v1, const T &v2) {
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

class Sale_data {};


int main(int argc, char const *argv[]) {
    Sale_data s1, s2;
    //invalid operands to binary expression ('const Sale_data' and 'const Sale_data')
    // std::cout << compare(s1, s2) << std::endl;
    return 0;
}
