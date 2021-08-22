/*
 *  为你的StrBlobPtr类添加加法和减法运算符，
 *  使其可以实现指针和算术运算（参见3.5.3节，第106页）。
 */

#include "include/StrBlob.h"
#include "include/StrBlobPtr.h"
#include <iostream>

int main(int argc, char const *argv[]) {
    StrBlob b{"Hello", "Hi", "Hey"};
    StrBlobPtr p(b);
    std::cout << (p + 2).deref() << std::endl;
    return 0;
}
