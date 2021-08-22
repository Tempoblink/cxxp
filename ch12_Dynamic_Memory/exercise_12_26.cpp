/*
 * 用allocator重写第427页的程序。
 */

#include <iostream>
#include <memory>
#include <string>

int main(int argc, char const *argv[]) {
    size_t n = 4;

    std::allocator<std::string> alloc;
    auto const p = alloc.allocate(n);

    std::string word;
    std::string *q = p;
    while (std::cin >> word && q != p + n)
        alloc.construct(q++, word);

    q = p;
    while (q && q != p + n)
        std::cout << *q++ << ' ';
    std::cout << std::endl;

    q = p;
    while (q && q != p + n)
        alloc.destroy(q++);
    alloc.deallocate(p, n);
    return 0;
}
