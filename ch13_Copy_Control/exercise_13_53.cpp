/*
 * 从底层效率的角度看，HasPtr的赋值运算符并不理想，解释为什么。
 * 为HasPtr实现一个拷贝赋值运算符和一个移动赋值运算符，
 * 并比较你的新的移动赋值运算符中执行的操作和拷贝并交换版本中执行的操作。
 */

#include <cstddef>
#include <iostream>
#include <string>
#include <type_traits>

class HasPtr {
public:
    HasPtr(const std::string &str = "") : ps(new std::string(str)), i(0) {}
    HasPtr(const HasPtr &h) : ps(new std::string(*h.ps)), i(h.i) { std::cout << "HasPtr(const HasPtr &)" << std::endl; }
    HasPtr(HasPtr &&h) noexcept : ps(h.ps), i(std::move(h.i)) {
        h.ps = nullptr;
        std::cout << "HasPtr(HasPtr &&)" << std::endl;
    }
    ~HasPtr() {
        if (ps) delete ps;
    }

    HasPtr &operator=(const HasPtr &);
    HasPtr &operator=(HasPtr &&) noexcept;

    std::string get_value() const { return *ps; }


private:
    std::string *ps;
    int i;
};


HasPtr &HasPtr::operator=(const HasPtr &h) {
    auto ret = new std::string(*h.ps);
    delete ps;
    ps = std::move(ret);
    i = h.i;
    std::cout << "operator=(HasPtr &)" << std::endl;
    return *this;
}
HasPtr &HasPtr::operator=(HasPtr &&h) noexcept {
    if (this != &h) {
        ps = h.ps;
        i = std::move(h.i);
        h.ps = nullptr;
    }
    std::cout << "operator=(HasPtr &&)" << std::endl;
    return *this;
}


int main(int argc, char const *argv[]) {
    HasPtr h1("Hello");
    HasPtr h2(h1);
    HasPtr h3;
    h3 = std::move(h1);
    std::cout << h2.get_value() << std::endl;
    std::cout << h3.get_value() << std::endl;
    return 0;
}
