/*
 * 为你的StrBlob类、StrBlobPtr类、StrVec类和String类定义下标运算符。
 */

#include "include/StrBlob.h"
#include "include/StrBlobPtr.h"
#include "include/StrVec.h"
#include "include/String.h"

int main(int argc, char const *argv[]) {
    StrBlob t1{"hello", "world"};
    std::cout << t1[0] << std::endl;
    StrBlobPtr p1(t1);
    std::cout << p1[1] << std::endl;
    StrVec sv1;
    sv1.push_back("Hello");
    std::cout << sv1[0] << std::endl;
    String s1("Hello");
    std::cout << s1[3]<< std::endl;
    return 0;
}
