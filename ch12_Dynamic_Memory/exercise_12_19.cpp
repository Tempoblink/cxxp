/*
 * 定义你自己版本的StrBlobPtr，更新StrBlob类，加入恰当的friend声明及begin和end成员。
 */

#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <sys/_types/_size_t.h>
#include <vector>

class StrBlob;

class StrBlobPtr {
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0);
    std::string &deref() const;
    StrBlobPtr &incr();

private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t i, const std::string &msg) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

class StrBlob {
    friend class StrBlobPtr;

public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    //增删
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();

    //查
    std::string &front();
    std::string &back();

    StrBlobPtr begin() { return StrBlobPtr(*this); }
    StrBlobPtr end() {
        auto ret = StrBlobPtr(*this, data->size());
        return ret;
    }

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};


StrBlobPtr::StrBlobPtr(StrBlob &a, size_t sz) : wptr(a.data), curr(sz) {}

void StrBlob::check(size_t i, const std::string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}

std::string &StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string &StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

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
    return (*p)[curr];
}


StrBlobPtr &StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}


int main(int argc, char const *argv[]) {
    return 0;
}
