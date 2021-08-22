/*
 * 为13.1.1节（第443页）练习13.5中的HasPtr类编写赋值运算符。
 * 类似拷贝构造函数，你的赋值运算符应该将对象拷贝到ps指向的位置。
 */


#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &);

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
