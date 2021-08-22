/*
 * 假设第550页的D1类需要覆盖它继承而来的fcn函数，
 * 你应该如何对其进行修改？如果你修改之后fcn匹配了Base中的定义，
 * 则该节的那些调用语句将如何解析？
 */

#include <iostream>

class Base {
public:
    virtual int fcn() {
        std::cout << " Base::fcn() ";
    }
};

class D1 : public Base {
public:
    int fcn() {
        std::cout << " D1::fcn() ";
    }
    virtual void f2() {
        std::cout << " D1::f2() ";
    }
};

class D2 : public D1 {
public:
    int fcn(int) {
        std::cout << " D2::fcn(int) ";
    }
    int fcn() {
        std::cout << " D2::fcn() ";
    }
    void f2() {
        std::cout << " D2::f2() ";
    }
};

int main(int argc, char const *argv[]) {
    Base bobj;
    D1 d1obj;
    D2 d2obj;

    Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
    std::cout << "bp1->fcn(): ", bp1->fcn(), std::cout << std::endl;//Base::fcn()
    std::cout << "bp2->fcn(): ", bp2->fcn(), std::cout << std::endl;//D1::fcn()
    std::cout << "bp3->fcn(): ", bp3->fcn(), std::cout << std::endl;//D2::fcn()

    D1 *d1p = &d1obj;
    D2 *d2p = &d2obj;
    // std::cout << "bp2->f2(): ", bp2->f2(), std::cout << std::endl;
    // bp2 的静态类型是Base 无法访问f2成员。
    std::cout << "d1p->f2(): ", d1p->f2(), std::cout << std::endl;//D1::f2()
    std::cout << "d2p->f2(): ", d2p->f2(), std::cout << std::endl;//D2::f2()

    Base *p1 = &d2obj;
    D1 *p2 = &d2obj;
    D2 *p3 = &d2obj;
    // std::cout << "p1->fcn(42): ", p1->fcn(42), std::cout << std::endl;
    // p1 的静态类型是Base， fcn为 fcn()
    // std::cout << "p2->fcn(42): ", p2->fcn(42), std::cout << std::endl;
    // p2 的静态类型是D1, fcn为 fcn()
    std::cout << "p3->fcn(42): ", p3->fcn(42), std::cout << std::endl;//D2::fcn(int)

    return 0;
}
