/*
 * 假定p1和p2指向同一个数组中的元素，则下面程序的功能是什么？为什么情况下该程序是非法的？
 * p1 += p2 - p1；
 */

/*
 * 该程序的含义是p1 = p1 + p2 - p1, p1 = p2;
 */

#include <iostream>

int main(void) {
    int arr[5] = {1, 2, 3, 4, 5};
    int *p1 = arr, *p2 = arr + 4;
    p1 += p2 - p1;
    std::cout << *p1 << std::endl;
    return 0;
}
