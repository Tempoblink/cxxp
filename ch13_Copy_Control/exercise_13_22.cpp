/*
 * 假定我们希望HasPtr的行为像一个值。
 * 即，对于对象所指向的string成员，每个对象都有一份自己的拷贝。
 * 我们将在下一节介绍拷贝控制成员的定义。
 * 但是，你已经学习了定义这些成员所需的所有知识。
 * 在继续学习下一节之前，为HasPtr编写拷贝构造函数和拷贝赋值运算符。
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
