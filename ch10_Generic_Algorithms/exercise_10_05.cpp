/*
 * 在本节对名册（roster）调用equal的例子中，如果两个名册中保存的都是C风格字符串而不是string，会发生什么？
 */

/*
 * 那么将会做指针的比较，而不是字符串内容的比较，显然是错误的。
 */

#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>

int main(int argc, char const *argv[]) {
    char a1[] = "Hello", a2[] = "Hello";
    std::vector<char *> cvec1{a1};
    std::vector<char *> cvec2{a2};
    std::cout << "a1[] = " << a1 << std::endl;
    std::cout << "a2[] = " << a2 << std::endl;
    std::cout << "Is they some? " << std::endl;
    std::cout << std::boolalpha
              << std::equal(cvec1.cbegin(), cvec1.cend(), cvec2.cbegin())
              << std::endl;
    return 0;
}
