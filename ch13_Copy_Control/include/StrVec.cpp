#include "StrVec.h"

StrVec::StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
StrVec::StrVec(const StrVec &s) {
    auto data = alloc_n_copy(s.begin(), s.end());
    elements = data.first;
    first_free = cap = data.second;
}

StrVec::StrVec(StrVec &&s) : elements(s.elements), first_free(s.first_free), cap(s.cap) {
    s.elements = s.first_free = s.cap = nullptr;
}
StrVec &StrVec::operator=(const StrVec &s) noexcept {
    auto data = alloc_n_copy(s.begin(), s.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}
StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

StrVec::~StrVec() { free(); }
void StrVec::push_back(const std::string &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}
std::pair<std::string *, std::string *> StrVec::alloc_n_copy(const std::string *begin, const std::string *end) {
    //分配一定大小的内存空间，返回首地址的指针
    auto data = alloc.allocate(end - begin);
    return {data, std::uninitialized_copy(begin, end, data)};
}
void StrVec::free() {
    //判断elements是否有元素
    if (elements) {
        for (auto p = first_free; p != elements;)
            //调用对象p的析构
            alloc.destroy(--p);
        //手动释放内存
        alloc.deallocate(elements, cap - elements);
    }
}
void StrVec::reallocate() {
    auto newcap = size() ? 2 * size() : 1;
    auto data = alloc.allocate(newcap);
    auto dest = data;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));

    free();
    elements = data;
    first_free = dest;
    cap = elements + newcap;
}
void StrVec::reserve(size_t n) {
    if (n <= capacity()) return;
    auto data = alloc.allocate(n);
    auto dest = data;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));

    free();
    elements = data;
    first_free = dest;
    cap = elements + n;
}
void StrVec::resize(size_t n) {
    if (n == size()) {
        return;
    } else {
        reallocate();
        while (first_free != elements + n) {
            if (n < size())
                alloc.destroy(--first_free);
            else
                alloc.construct(first_free++);
        }
    }
}

std::allocator<std::string> StrVec::alloc;
