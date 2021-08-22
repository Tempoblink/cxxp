/*
 * 定义你自己的使用引用计数版本的HasPtr。
 */

#include <cstddef>
#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0), ptr_count(new std::size_t(1)) {}
    HasPtr(const HasPtr &);
    HasPtr &operator=(const HasPtr &);
    ~HasPtr();

private:
    std::string *ps;
    int i;
    std::size_t *ptr_count;
};

HasPtr::HasPtr(const HasPtr &h) : ps(new std::string(*h.ps)), i(h.i), ptr_count(h.ptr_count) { ++*ptr_count; }

HasPtr &HasPtr::operator=(const HasPtr &h) {
    ++*h.ptr_count;
    if (--*ptr_count) {
        delete ps;
        delete ptr_count;
    }
    ps = h.ps;
    i = h.i;
    ptr_count = h.ptr_count;
    return *this;
}

HasPtr::~HasPtr() {
    if (--*ptr_count) {
        delete ps;
        delete ptr_count;
    }
}

int main(int argc, char const *argv[]) {
    return 0;
}
