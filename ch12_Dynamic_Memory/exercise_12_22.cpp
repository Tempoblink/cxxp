/*
 * 为了能让StrBlobPtr使用const StrBlob，你觉得应该如何修改？
 * 定义一个名为ConstStrBlobPtr的类，使其能够指向const StrBlob。
 */

#include <cstddef>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

class StrBlob;

class ConstStrBlobPtr {
public:
    ConstStrBlobPtr() : curr(0){};
    ConstStrBlobPtr(const StrBlob &a, std::size_t sz = 0);

    const std::string &dedef() const;
    ConstStrBlobPtr &incr();

private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

//StrBlob
class StrBlob {
    friend class ConstStrBlobPtr;

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

    ConstStrBlobPtr begin() { return ConstStrBlobPtr(*this); }
    ConstStrBlobPtr end() {
        auto ret = ConstStrBlobPtr(*this, data->size());
        return ret;
    }

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};


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
