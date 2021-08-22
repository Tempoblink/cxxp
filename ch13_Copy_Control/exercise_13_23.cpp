/*
 * 比较上一节练习中你编写的拷贝控制成员和这一节中的代码。
 * 确定你理解了你的代码和我们的代码之间的差异（如果有的话）。
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
