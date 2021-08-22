/*
 * 编写函数f的4个版本，令其各输出一条可以区分的消息。
 * 验证上一个练习的答案，如果你回答错了，反复研究本节的内容直到你弄清自己错在何处。
 */

#include <iostream>

void f() {
    std::cout << "void f()" << std::endl;
}

void f(int) {
    std::cout << "void f(int)" << std::endl;
}

void f(int, int) {
    std::cout << "void f(int, int)" << std::endl;
}

void f(double, double = 3.14) {
    std::cout << "void f(double, double = 3.14)" << std::endl;
}

int main(void) {
    //f(2.56, 42);
    f(42);
    f(42, 0);
    f(2.56, 3.14);
    return 0;
}
