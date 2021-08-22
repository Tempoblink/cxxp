/*
 * 请叙述下面这段代码的作用
 *
 * int i = 42;
 * int *p1 = &i;
 * *p1 = *p1 * *p1;
 */

/*
 * i = i * i；
 */

#include <iostream>

int main(void) {
    int i = 42;
    int *p1 = &i;
    *p1 = *p1 * *p1;
    std::cout << "*p1 = " << *p1 << std::endl;
    return 0;
}
