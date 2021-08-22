/*
 * 假设给定了第543页和第544页的类，
 * 同时已知每个对象的类型如注释所示，
 * 判断下面的哪些赋值语句是合法的。
 * 解释那些不合法的语句为什么不被允许：
 *
 * Base *p = &d1;     // d1的类型是Pub_Derv
 * p = &d2;           // d2的类型是Priv_Derv
 * p = &d3;           // d3的类型是Prot_Derv
 * p = &dd1;          // dd1的类型是Derived_from_Public
 * p = &dd2;          // dd2的类型是Derived_from_Private
 * p = &dd2;          // dd3的类型是Derived_from_Protected
 */

/*
 * Pub_Derv ---> base
 * 合法，Pub_Derv是Base的派生类public继承
 * 非法，Priv_Derv是privete继承，无法派生向基类转换
 * 非法，Prot_Derv是protect继承，无法派生向基类转换
 * 合法，public --> public --> Base
 * 非法，public --> private --> Base
 * 非法，public --> protect --> Base
 */

#include <iostream>

class Base {
public:
    void pub_mem() { std::cout << "Base::pub_mem()" << std::endl; }

protected:
    int prot_mem() {
        std::cout << "Base::prot_mem()" << std::endl;
        return 0;
    }

private:
    char priv_mem() {
        std::cout << "Base::priv_mem()" << std::endl;
        return '0';
    }
};


struct Pub_Derv : public Base {
    int f() {
        std::cout << "Pub_Derv::f()"
                  << "  ";
        return prot_mem();
    }
    char g() {
        std::cout << "Pub_Derv::g()"
                  << "  ";
        // return priv_mem();
        return '1';
    }
};

struct Prot_Derv : protected Base {
    int f() {
        std::cout << "Prot_Derv::f()"
                  << "  ";
        return prot_mem();
    }
    char g() {
        std::cout << "Prot_Derv::g()"
                  << "  ";
        // return priv_mem();
        return '2';
    }
};

struct Prive_Derv : private Base {
    int f() {
        std::cout << "Prive_Derv::f1()"
                  << "  ";
        return prot_mem();
    }
    char g() {
        std::cout << "Prive_Derv::g1()"
                  << "  ";
        // return priv_mem();
        return '3';
    }
};

struct Derived_from_Public : public Pub_Derv {
    int use_base() {
        std::cout << "Derived_from_Public::use_base()"
                  << "  ";
        return prot_mem();
    }
};

struct Derived_from_Private : public Prive_Derv {
    int use_base() {
        std::cout << "Derived_from_Private::use_base()"
                  << "  ";
        // return prot_mem();
    }
};

int main(int argc, char const *argv[]) {

    return 0;
}
