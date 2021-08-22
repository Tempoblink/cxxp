/*
 * 说明形参、局部变量以及局部静态变量的区别。编写一个函数，同时用到这三种形式。
 */

/*
 * 形参和普通局部变量都是自动变量，形参在函数执行时初始化（且必须使用实参初始化），
 * 并在函数结束时销毁。普通局部变量在第一次执行定义语句时初始化，在块结束时销毁。
 * 局部静态变量只在第一次执行定义语句时初始化一次，且生命周期伴随进程。
 */

#include <iostream>

int foo(int val) {
    static int b = 0;
    b += val;
    return b;
}

int main(void) {
    //static b = 0;
    std::cout << "foo(1) = 0 + 1 = " << foo(1) << std::endl;
    //static b = 1 ;
    std::cout << "foo(2) = 1 + 2 = " << foo(2) << std::endl;
    //static b = 3;
    std::cout << "foo(3) = 3 + 3 = " << foo(3) << std::endl;
    return 0;
}
