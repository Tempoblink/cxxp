/*
 * 为你的StrBlobPtr类添加递增和递减运算符。
 */

#include "include/StrBlob.h"
#include "include/StrBlobPtr.h"
#include <iostream>

int main(int argc, char const *argv[]) {
    StrBlob t1{"Hello", "Hi", "Hey"};
    StrBlobPtr p1(t1);
    while (p1 != t1.end()) {
        std::cout << p1.deref() << std::endl;
        ++p1;
    }
    return 0;
}
