/*
 * 说明由decltype指定类型和由auto指定类型有何区别。
 * 请举出一个例子，decltype指定的类型与auto指定的类型一样；
 * 再举一个例子，decltype指定的类型与auto指定的类型不一样。
 */

#include <iostream>

int main(void) {
    int a = 0, b = 1, &c = b;
    std::cout << "a = " << a << " at " << reinterpret_cast<int_fast64_t>(&a) << std::endl;
    std::cout << "b = " << b << " at " << reinterpret_cast<int_fast64_t>(&b) << std::endl;
    std::cout << "c = " << c << " at " << reinterpret_cast<int_fast64_t>(&c) << std::endl;

    //一样
    std::cout << "decltype指定的类型与auto指定的类型一样: " << std::endl;
    auto d = a;
    decltype(a) e = a;
    std::cout << "d = " << d << " at " << reinterpret_cast<int_fast64_t>(&d) << std::endl;
    std::cout << "e = " << e << " at " << reinterpret_cast<int_fast64_t>(&e) << std::endl;

    //不一样
    std::cout << "decltype指定的类型与auto指定的类型不一样: " << std::endl;
    auto f = c;
    decltype(c) g = c;
    std::cout << "f = " << f << " at " << reinterpret_cast<int_fast64_t>(&f) << std::endl;
    std::cout << "g = " << g << " at " << reinterpret_cast<int_fast64_t>(&g) << std::endl;
    return 0;
}
