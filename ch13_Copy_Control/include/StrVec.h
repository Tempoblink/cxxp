#pragma once

#include <iterator>
#include <memory>
#include <string>
#include <utility>

class StrVec {

public:
    StrVec();
    StrVec(const StrVec &);
    StrVec(StrVec &&);
    StrVec &operator=(const StrVec &) noexcept;
    StrVec &operator=(StrVec &&) noexcept;
    ~StrVec();

    void push_back(const std::string &);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    void reserve(size_t n);
    void resize(size_t n);

    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }

private:
    static std::allocator<std::string> alloc;
    void chk_n_alloc() {
        if (size() == capacity()) reallocate();
    }
    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);

    void free();
    void reallocate();

    std::string *elements;
    std::string *first_free;
    std::string *cap;
};
