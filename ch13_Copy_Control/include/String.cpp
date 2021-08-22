#include "String.h"
#include <algorithm>
#include <iterator>
#include <memory>
String::String() : first(nullptr), last(nullptr), cap(nullptr) {}
String::String(const char *s) {
    auto p = s;
    while (*p != '\0') ++p;
    auto data = alloc_n_copy(s, p);
    first = data.first;
    last = cap = data.second;
}
String::String(const String &s) {
    auto data = alloc_n_copy(s.begin(), s.end());
    first = data.first;
    last = cap = data.second;
    std::cout << "String(const String &)" << std::endl;
}
String::String(String &&s) {
    if (this != &s) {
        first = s.first;
        last = s.last;
        cap = s.cap;
        s.first = s.last = s.cap = nullptr;
    }
    std::cout << "String(String &&)" << std::endl;
}

String::~String() {
    free();
}

String &String::operator=(const String &s) {
    auto data = alloc_n_copy(s.begin(), s.end());
    free();
    first = data.first;
    last = cap = data.second;
    std::cout << "operator=(const String &)" << std::endl;
    return *this;
}

String &String::operator=(String &&rhs) {
    if (this != &rhs) {
        first = rhs.first;
        last = rhs.last;
        cap = rhs.cap;
        rhs.first = rhs.last = rhs.cap = nullptr;
    }
    std::cout << "operator=(String &&)" << std::endl;
    return *this;
}

std::allocator<char> String::alloc;

std::pair<char *, char *> String::alloc_n_copy(const char *begin, const char *end) {
    auto data = alloc.allocate(end - begin);
    return {data, std::uninitialized_copy(begin, end, data)};
}

void String::free() {
    if (first)
        std::for_each(first, last, [](char &s) { alloc.destroy(&s); });
    alloc.deallocate(first, cap - first);
}
void String::reallocte() {
    auto newcap = size() ? size() * 2 : 1;
    auto data = alloc.allocate(newcap);
    auto dest = data;
    auto elem = first;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    first = data;
    last = dest;
    cap = first + newcap;
}
