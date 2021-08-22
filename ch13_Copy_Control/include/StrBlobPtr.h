#pragma once
#include <memory>
#include <string>
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
