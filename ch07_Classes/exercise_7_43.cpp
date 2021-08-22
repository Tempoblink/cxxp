/*
 * 假定有一个名为NoDefault的类，它有一个接受int的构造函数，但是没有默认构造函数。
 * 定义类C，C有一个NoDefault类型的成员，定义C的默认构造函数。
 */
#include <iostream>


class NoDefault {
public:
    //NoDefault() = default;
    NoDefault(int) {}
};

class C {
public:
    //C() = default;
    C() : no(0) {}

private:
    NoDefault no;
};

int main(void) {
    C c;
    return 0;
}
