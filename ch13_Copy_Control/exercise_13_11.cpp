/*
 * 为前面练习中的HasPtr类添加一个析构函数。
 */

#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &);
    ~HasPtr() { delete ps; };
    HasPtr &operator=(const HasPtr &);

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

int main(int argc, char const *argv[]) {
    return 0;
}
