
#include "ConstStrBlobPtr.h"
#include "StrBlob.h"


ConstStrBlobPtr::ConstStrBlobPtr(const StrBlob &a, std::size_t sz) : wptr(a.data), curr(sz) {}


std::shared_ptr<std::vector<std::string>> ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret)
        std::runtime_error("unbound ConstStrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

const std::string &ConstStrBlobPtr::dedef() const {
    auto p = check(curr, "deference past end");
    return (*p)[curr];
}


ConstStrBlobPtr &ConstStrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}
const std::string &ConstStrBlobPtr::operator*() const {
    auto p = check(curr, "deference past end");
    return (*p)[curr];
}
const std::string *ConstStrBlobPtr::operator->() const {
    //this指针 -> 访问 解引用函数。 返回指针，然后指针继续->访问
    return &this->operator*();
}
