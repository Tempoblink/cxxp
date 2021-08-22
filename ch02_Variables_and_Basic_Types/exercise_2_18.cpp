/*
 * 编写代码分别更改指针的值以及指针所指对象的值
 */

#include <iostream>

int main(void) {
    int i = 0, j = 1;
    std::cout << "i = " << i << std::endl;
    std::cout << "j = " << j << std::endl;
    int *p = &i;
    std::cout << "p = " << *p << " at " << reinterpret_cast<int_fast64_t>(&*p) << std::endl;
    *p = 2;
    std::cout << "p = " << *p << " at " << reinterpret_cast<int_fast64_t>(&*p) << std::endl;
    p = &j;
    std::cout << "p = " << *p << " at " << reinterpret_cast<int_fast64_t>(&*p) << std::endl;
    return 1;
}
