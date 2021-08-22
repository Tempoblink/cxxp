/*
 * 给定上一题中的类以及下面这些对象，说明在运行时调用哪个函数？
 *
 * base bobj;      base *bp1 = &bobj;    base &br1 = bobj;
 * derived dobj;   base *bp2 = &dobj;    base &br2 = dobj;
 *
 * (a) bobj.print();      (b) dobj.print();     (c) bp1->name();
 * (d) bp2->name();       (e) br1.print();      (f) br2.print();
 */

/*
 * (a) base::print()
 * (b) derived::print()
 * (c) base::name()
 * (d) base::name()
 * (e) base::print()
 * (f) derived::print()
 */

#include <iostream>
#include <string>

class base {
public:
    std::string name() {
        std::cout << "base::name()" << std::endl;
        return basename;
    }
    virtual void print(std::ostream &os = std::cout) {
        std::cout << "base::print()" << std::endl;
        os << basename;
    }

private:
    std::string basename;
};

class derived : public base {
public:
    void print(std::ostream &os = std::cout) {
        std::cout << "derived::print()" << std::endl;
        base::print(os);
        os << " " << i;
    }

private:
    int i;
};

int main(int argc, char const *argv[]) {
    base bobj;
    base *bp1 = &bobj;
    base &br1 = bobj;
    derived dobj;
    base *bp2 = &dobj;
    base &br2 = dobj;

    std::cout << "bobj.print(): \t", bobj.print(), std::cout << std::endl;
    std::cout << "dobj.print(): \t", dobj.print(), std::cout << std::endl;
    std::cout << "bp1->name(): \t", bp1->name(), std::cout << std::endl;
    std::cout << "bp2->name(): \t", bp2->name(), std::cout << std::endl;
    std::cout << "br1.print(): \t", br1.print(std::cout), std::cout << std::endl;
    std::cout << "br2.print(): \t", br2.print(std::cout), std::cout << std::endl;
    return 0;
}
