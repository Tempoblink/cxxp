/*
 * 推断下面代码的输出结果并说明理由。实际运行这段程序，结果和你想象的一样吗？如果不一样，为什么？
 *
 * int x[10];   int *p = x;
 * cout << sizeof(x) / sizeof(*x) << endl;
 * cout << sizeof(p) / sizeof(*p) << endl;
 */

/*
 * 10
 * 2 指针本身的内存大小是8字节，int类型的内存大小是4字节。
 */

#include <iostream>

int main(void) {
    int x[10];
    int *p = x;
    std::cout << "sizeof(x) / sizeof(*x) = " << sizeof(x) / sizeof(*x) << std::endl;
    std::cout << "sizeof(p) / sizeof(*p) = " << sizeof(p) / sizeof(*p) << std::endl;
    return 0;
}
