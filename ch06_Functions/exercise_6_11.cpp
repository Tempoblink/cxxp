/*
 * 编写并验证你自己的reset函数，使其作用于引用类型的参数。
 */

#include <iostream>

void ret(int &i) {
    i = 0;
}

int main(void) {
    int i = 2;
    std::cout << "i = " << i << std::endl;
    ret(i);
    std::cout << "ret(i) = " << i << std::endl;
    return 0;
}
