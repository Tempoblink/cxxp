/*
 * 练习2.7：下述字面值表示何种含义？它们各自的数据类型是什么？
 *
 * (a) "Who goes with F\145rgus?\012"
 * (b) 3.14e1L         (c) 1024f      (d) 3.14L
 */

/*
 * (a) 表示字符串字面量："Who goes with Fergus?\t"
 * (b) long double
 * (c) float
 * (d) long double
 */

#include <iostream>

int main(void) {
    std::cout << "Who goes with F\145rgus?\012";

    return 0;
}
