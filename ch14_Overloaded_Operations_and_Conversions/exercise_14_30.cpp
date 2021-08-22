/*
 * 为你的StrBlobPtr类和在12.1.6节练习12.22（第423页）中定义的ConstStrBlobPtr类分别添加解引用运算符和箭头运算符。
 * 注意：因为ConstStrBlobPtr的数据成员指向const vector，所以ConstStrBlobPtr中的运算符必须返回常量引用。
 */

#include "include/ConstStrBlobPtr.h"
#include "include/StrBlob.h"
#include "include/StrBlobPtr.h"
#include <iostream>

int main(int argc, char const *argv[]) {
    StrBlob b{"Hello", "Hi", "Hey"};
    StrBlobPtr p1(b, 2);
    ConstStrBlobPtr p2(b);
    std::cout << p1->size() << std::endl;
    std::cout << p2->size() << std::endl;

    return 0;
}
