/*
 * 为你的HasPtr类定义一个<运算符，并定义一个HasPtr的vector。
 * 为这个vector添加一些元素，并对它执行sort。注意何时会调用swap。
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class HasPtr {
    friend void swap(HasPtr &lhs, HasPtr &rhs);

public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &);
    ~HasPtr() { delete ps; };
    HasPtr &operator=(const HasPtr &);
    bool operator<(const HasPtr &rhs) const { return *ps < *rhs.ps; }

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
    std::vector<HasPtr> p;
    p.emplace_back("Hello");
    p.emplace_back("Hi");
    p.emplace_back("Hey");

    for (const auto &s : p) {
        std::cout << s.get_value() << " ";
    }
    std::cout << std::endl;
    std::cout << "------sort------" << std::endl;
    std::sort(p.begin(), p.end());
    for (const auto &s : p) {
        std::cout << s.get_value() << " ";
    }
    std::cout << std::endl;

    std::cout << "-----check-----" << std::endl;
    std::vector<std::string> s{
            "Hello",
            "Hi",
            "Hey"};
    for (const auto &m : s) {
        std::cout << m << " ";
    }
    std::cout << std::endl;
    std::cout << "------sort------" << std::endl;
    std::sort(s.begin(), s.end());
    for (const auto &m : s) {
        std::cout << m << " ";
    }
    std::cout << std::endl;


    return 0;
}
