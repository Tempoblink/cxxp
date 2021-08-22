/*
 * 编写程序，将一个list中的char*指针（指向C风格字符串）元素赋值给一个vector中的string。
 */

#include <iostream>
#include <list>
#include <string>
#include <vector>

int main(void) {
    std::list<char *> cptr_li;
    char c1[] = "Hello,world!";
    char c2[] = "Good day!";
    char c3[] = "Have fun!";
    cptr_li = {c1, c2, c3};

    std::vector<std::string> svec;
    svec.assign(cptr_li.cbegin(), cptr_li.cend());

    for (const auto &i : svec) {
        std::cout << i << std::endl;
    }
    return 0;
}
