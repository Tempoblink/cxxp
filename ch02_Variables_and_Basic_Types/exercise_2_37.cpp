/*
 * 赋值是会产生引用的一类典型表达式，引用的类型就是左值的类型。也就是说，如果i是int，表达式i = x的类型是int&。
 * 根据这一特点，请指出下面的代码中每一个变量的类型和值。
 *
 * int a = 3, b = 4;
 * decltype(a) c = a;
 * decltype(a = b) d = a;
 */

/*
 * a->int     b->int
 * c->int     d->int&
 *
 * a = 3, b = 4, c = 3, d = 3;
 */

#include <iostream>

int main(void) {
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype(a = b) d = a;

    std::cout << "a = " << a << " at " << reinterpret_cast<int_fast64_t>(&a) << std::endl;
    std::cout << "b = " << b << " at " << reinterpret_cast<int_fast64_t>(&b) << std::endl;
    std::cout << "c = " << c << " at " << reinterpret_cast<int_fast64_t>(&c) << std::endl;
    std::cout << "d = " << d << " at " << reinterpret_cast<int_fast64_t>(&d) << std::endl;

    return 0;
}
