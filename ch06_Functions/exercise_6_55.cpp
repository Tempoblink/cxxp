/*
 * 编写4个函数，分别对两个int值执行加、减、乘、除运算；
 * 在上一题创建的vector对象中保存指向这些函数的指针。
 */

#include <iostream>
#include <vector>

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mutli(int a, int b) {
    return a * b;
}

int dev(int a, int b) {
    return 1.0 * a / b;
}

int main(void) {
    using pf = int (*)(int, int);
    std::vector<pf> pfvec;
    pfvec.push_back(add);
    pfvec.push_back(sub);
    pfvec.push_back(mutli);
    pfvec.push_back(dev);
    return 0;
}
