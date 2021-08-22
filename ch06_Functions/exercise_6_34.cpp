/*
 * 如果factorial函数的停止条件如下所示，将发生什么情况？
 * if (val != 0)
 */

/*
 * 如果val是个负数，那么函数将永远递归下去，直到栈溢出。提示：Segmentation fault (core dumped)
 */

#include <iostream>

int factorial(int val) {
    //if(val > 0)
    if (val != 0)
        return factorial(val - 1) * val;
    return 1;
}

int main(void) {
    int sum = factorial(5);
    std::cout << "5! = " << sum << std::endl;
    return 0;
}
