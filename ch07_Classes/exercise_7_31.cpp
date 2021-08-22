/*
 * 定义一对类X和Y，其中X包含一个指向Y的指针，而Y包含一个类型为X的对象。
 */

#include <iostream>
#include <string>

class X;
class Y;

class X {
public:
    Y *m_ptr;
};

class Y {
public:
    X m_p;
};

int main(void) {
    return 0;
}
