/*
 * 假定希望定义StrBlob的类值版本，而且希望继续使用shared_ptr，
 * 这样我们的StrBlobPtr类就仍能使用指向vector的weak_ptr了。
 * 你修改后的类将需要一个拷贝构造函数和一个拷贝赋值运算符，但不需要析构函数。
 * 解释拷贝构造函数和拷贝赋值运算符必须要做什么。
 * 解释为什么不需要析构函数。
 */

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class StrBlob;

void print(std::ostream &, const StrBlob &);

class StrBlob {
    friend void print(std::ostream &, const StrBlob &);

public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    StrBlob(const StrBlob &);
    StrBlob &operator=(const StrBlob &);

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    //增删
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();
    //查
    std::string &front();
    std::string &back();

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}
StrBlob::StrBlob(const StrBlob &s) {
    auto new_data = std::make_shared<std::vector<std::string>>(*s.data);
    data = new_data;
}
StrBlob &StrBlob::operator=(const StrBlob &rhs) {
    auto new_data = std::make_shared<std::vector<std::string>>(*rhs.data);
    data = new_data;
    return *this;
}


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

void print(std::ostream &os, const StrBlob &s) {
    for (auto &mem : *s.data) {
        os << mem << " ";
    }
    os << std::endl;
}

int main(int argc, char const *argv[]) {
    StrBlob s1({"hello", "world"});
    StrBlob s2(s1);
    StrBlob s3 = s2;

    print(std::cout, s1);
    print(std::cout, s2);
    print(std::cout, s3);

    s1.push_back("s1");
    s2.push_back("s2");
    s3.push_back("s3");

    print(std::cout, s1);
    print(std::cout, s2);
    print(std::cout, s3);
}
