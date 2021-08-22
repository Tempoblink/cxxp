/*
 * 为你的StrBlob添加一个右值引用版本的push_back。
 */

#include "include/StrBlobPtr.h"
#include <__bit_reference>
#include <initializer_list>
#include <iostream>
#include <string>
#include <vector>

class StrBlob {
    friend class StrBlobPtr;

public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    //增删
    void push_back(const std::string &t) {
        data->push_back(t);
        std::cout << "push_back(const std::string &)" << std::endl;
    }
    void push_back(std::string &&t) {
        data->push_back(std::move(t));
        std::cout << "push_back(std::string &&)" << std::endl;
    }
    void pop_back();
    //查
    std::string &front();
    std::string &back();
    StrBlobPtr begin();
    StrBlobPtr end();

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}


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

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end() {
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}


int main(int argc, char const *argv[]) {
    StrBlob test1;
    test1.push_back("Hello");
    return 0;
}
