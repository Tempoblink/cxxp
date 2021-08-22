/*
 * 为你的StrVec、String和Message类添加一个移动构造函数和一个移动赋值运算符。
 */

#include "include/String.h"

String func() {
    String s1 = "func()";
    return s1;
}

int main(int argc, char const *argv[]) {
    String s1 = "Hello";
    String s2;
    s2 = func();
    String s3(std::move(s1));
    return 0;
}
