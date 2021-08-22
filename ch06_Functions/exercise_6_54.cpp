/*
 * 编写函数声明，令其接受两个int形参并且返回类型也是int，
 * 然后声明一个vector对象，令其元素是指向该函数的指针。
 */

#include <iostream>
#include <vector>

int func(int a, int b);

int main(void) {
    int (*pf)(int, int);
    std::vector<decltype(pf)*> pfvec;

    using qf = int (*)(int, int);
    std::vector<qf> qfvec;
    return 0;
}
