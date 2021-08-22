#pragma once
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

    const std::string &operator*() const;
    const std::string *operator->() const;

    const std::string &dedef() const;
    ConstStrBlobPtr &incr();

private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};
