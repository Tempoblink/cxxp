/*
 * 为你的StrVec类定义一个initializer_list赋值运算符。
 */

#include "include/StrVec.h"
#include <iostream>

int main(int argc, char const *argv[]) {

    StrVec svec;
    svec = {"Hello", "World"};
    for (const auto &msg : svec)
        std::cout << msg << " ";
    std::cout << std::endl;
    return 0;
}
