/*
 * 为你的StrBlob类、StrBlobPtr类、StrVec类和String类定义关系运算符。
 */

#include "include/StrBlob.h"
#include "include/StrBlobPtr.h"
#include "include/StrVec.h"
#include "include/String.h"

int main(int argc, char const *argv[]) {
    StrBlob t1{"hello", "world"};
    StrBlob t2{"hello", "world"};
    std::cout << std::boolalpha << (t1 <t2) << std::endl;
    StrBlobPtr p1(t1);
    StrBlobPtr p2(t2);
    std::cout << std::boolalpha << (p1 < p2) << std::endl;
    StrVec sv1;
    sv1.push_back("Hello");
    StrVec sv2;
    sv2.push_back("Hello");
    std::cout << std::boolalpha << (sv1 < sv2) << std::endl;
    String s1("Hello");
    String s2("Hell");
    std::cout << std::boolalpha << (s2 < s1) << std::endl;

    return 0;
}
