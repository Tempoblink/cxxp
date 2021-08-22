/*
 * 下面的赋值是非法的，为什么？应该如何修改？
 *
 * double dval; int ival; int *pi;
 * dval = ival = pi = 0;
 */

/*
 * 先给指针赋值成空指针，后将pi赋值给ival时错误，无法将指针类型赋值给int整型。
 *
 * dval = ival = *pi = 0;
 */

#include <iostream>

int main(void) {
    double dval;
    int ival;
    int *pi;
    dval = ival = 0;
    pi = 0;
    std::cout << "dval = " << dval << std::endl;
    std::cout << "ival = " << ival << std::endl;
    std::cout << "pi = " << pi << std::endl;
    return 0;
}
