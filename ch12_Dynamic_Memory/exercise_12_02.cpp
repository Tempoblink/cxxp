/*
 * 编写你自己的StrBlob类，包含const版本的front和back。
 */

#include <initializer_list>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

class StrBlob {
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

    const std::string &cfront() const;
    const std::string &cback() const;

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

//构建
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

const std::string &StrBlob::cfront() const {
    check(0, "cfront on empty StrBlob");
    return data->front();
}
const std::string &StrBlob::cback() const {
    check(0, "cback on empty StrBlob");
    return data->back();
}

int main(int argc, char const *argv[]) {
    return 0;
}
