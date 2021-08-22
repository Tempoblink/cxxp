#include "StrBlobPtr.h"
#include "StrBlob.h"

StrBlobPtr::StrBlobPtr(StrBlob &a, size_t sz) : wptr(a.data), curr(sz) {}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbonud StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}


std::string &StrBlobPtr::deref() const {
    auto p = check(curr, "difference past end");
    //返回当前位置容器的存储的值
    return (*p)[curr];
}


StrBlobPtr &StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return (lhs.wptr.lock() == rhs.wptr.lock()) && (lhs.curr == rhs.curr);
}
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !(lhs == rhs);
}
bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return (lhs.wptr.lock() == rhs.wptr.lock()) && (lhs.curr < rhs.curr);
}
std::string &StrBlobPtr::operator[](std::size_t n) {
    auto p = check(n, "out_of_range");
    return *(p->begin() + n);
}
const std::string &StrBlobPtr::operator[](std::size_t n) const {
    auto p = check(n, "out_of_range");
    return *(p->begin() + n);
}
StrBlobPtr &StrBlobPtr::operator++() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}
StrBlobPtr &StrBlobPtr::operator--() {
    --curr;
    check(curr, "decrement past begin of StrBlobPtr");
    return *this;
}
StrBlobPtr StrBlobPtr::operator++(int) {
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}
StrBlobPtr StrBlobPtr::operator--(int) {
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}
StrBlobPtr operator+(const StrBlobPtr &lhs, const std::size_t &n) {
    auto pos = lhs.curr + n;
    lhs.check(pos, "out_of_range");
    StrBlobPtr ret = lhs;
    ret.curr = pos;
    return ret;
}
StrBlobPtr operator-(const StrBlobPtr &lhs, const std::size_t &n) {
    auto pos = lhs.curr - n;
    lhs.check(pos, "out_of_range");
    StrBlobPtr ret = lhs;
    ret.curr = pos;
    return ret;
}
std::string &StrBlobPtr::operator*() const {
    auto p = check(curr, "out_of_range");
    return (*p)[curr];
}
std::string *StrBlobPtr::operator->() const {
    return &operator*();
}
