/*
 * 分别用while循环和传统的for循环重写第一题的程序，
 * 你觉得哪种形式更好呢？为什么？
 */

#include <iostream>
#include <string>

int main(void) {
    std::string tmp1("good day, have fun!");
    decltype(tmp1.size()) i = 0;
    while (i != tmp1.size()) {
        tmp1[i] = 'x';
        ++i;
    }
    std::cout << tmp1 << std::endl;


    std::string tmp2("good day, have fun!");
    for (decltype(tmp2.size()) i = 0; i != tmp2.size(); ++i) {
        tmp2[i] = 'x';
    }
    std::cout << tmp2 << std::endl;
    return 0;
}
