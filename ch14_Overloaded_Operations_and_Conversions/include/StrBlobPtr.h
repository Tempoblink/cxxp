#pragma once
#include <memory>
#include <string>
#include <vector>

class StrBlob;

class StrBlobPtr {
    friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
    friend StrBlobPtr operator+(const StrBlobPtr &, const std::size_t &);
    friend StrBlobPtr operator-(const StrBlobPtr &, const std::size_t &);

public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0);
    std::string &deref() const;
    StrBlobPtr &incr();
    std::string &operator[](std::size_t);
    const std::string &operator[](std::size_t) const;
    StrBlobPtr &operator++();
    StrBlobPtr &operator--();
    StrBlobPtr operator++(int);
    StrBlobPtr operator--(int);
    std::string &operator*() const;
    std::string *operator->() const;

private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t i, const std::string &msg) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};
