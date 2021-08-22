/*
 * 为你的类值版本的HasPtr编写swap函数，并测试它。
 * 为你的swap函数添加一个打印语句，指出函数什么时候执行。
 */

#include <iostream>
#include <string>
#include <utility>

class HasPtr {
    friend void swap(HasPtr &lhs, HasPtr &rhs);

public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &);
    ~HasPtr() { delete ps; };
    HasPtr &operator=(const HasPtr &);

    std::string get_value() const { return *ps; }

private:
    std::string *ps;
    int i;
};

HasPtr::HasPtr(const HasPtr &h) : ps(new std::string(*h.ps)), i(h.i) {}

HasPtr &HasPtr::operator=(const HasPtr &rhs) {
    auto p = new std::string(*rhs.ps);
    delete ps;
    ps = p;
    i = rhs.i;
    return *this;
}

inline void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}


int main(int argc, char const *argv[]) {
    HasPtr p1("p1"), p2("p2");
    std::cout << "p1 = " << p1.get_value() << std::endl;
    std::cout << "p2 = " << p2.get_value() << std::endl;
    std::cout << "------swap------" << std::endl;
    swap(p1, p2);
    std::cout << "p1 = " << p1.get_value() << std::endl;
    std::cout << "p2 = " << p2.get_value() << std::endl;
    return 0;
}
