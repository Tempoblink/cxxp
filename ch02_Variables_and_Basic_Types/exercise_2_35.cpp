/*
 * 判断下列定义判断出的类型是什么，然后编写程序进行验证。
 *
 * const int i = 42;
 * auto j = i; const auto &k = i; auto *p = &i;
 * const auto j2 = i, &k2 = i;
 */

/*
 * i 是 常量整数型
 * j 是 整数型
 * k 是 常用整数引用
 * p 是 指向常量的指针
 * j2是 常量整数型
 * k2是 常量整数型引用
 */


#include <iostream>

int main(void) {
    const int i = 42;
    auto j = i;
    const auto &k = i;
    auto *p = &i;
    const auto j2 = i, &k2 = i;

    std::cout << "i = " << i << " at " << reinterpret_cast<int_fast64_t>(&i) << std::endl;

    std::cout << "j = " << j << " at " << reinterpret_cast<int_fast64_t>(&j) << std::endl;
    std::cout << "k = " << k << " at " << reinterpret_cast<int_fast64_t>(&k) << std::endl;
    std::cout << "p = " << *p << " at " << reinterpret_cast<int_fast64_t>(&p) << std::endl;
    std::cout << "j2 = " << j2 << " at " << reinterpret_cast<int_fast64_t>(&j2) << std::endl;
    std::cout << "k2 = " << k2 << " at " << reinterpret_cast<int_fast64_t>(&k2) << std::endl;

    return 0;
}
