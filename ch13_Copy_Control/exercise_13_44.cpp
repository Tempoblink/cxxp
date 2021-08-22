/*
 * 编写标准库string类的简化版本，命名为String。
 * 你的类应该至少有一个默认构造函数和一个接受C风格字符串指针参数的构造函数。
 * 使用allocator为你的String类分配所需内存。
 */

#include <iostream>
#include <memory>
#include <utility>

class String {
    friend std::ostream &operator<<(std::ostream &, const String &);
    friend std::istream &operator>>(std::istream &, String &);

public:
    String();
    String(const char *);
    String(const String &);
    String &operator=(const String &);
    ~String();

    char *begin() const { return first; }
    char *end() const { return last; }
    size_t size() const { return last - first; }

private:
    static std::allocator<char> alloc;
    std::pair<char *, char *> alloc_n_copy(const char *, const char *);
    void free();
    char *first;
    char *last;
    char *cap;
};

std::allocator<char> String::alloc;

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
}

String::~String() {
    free();
}

String &String::operator=(const String &s) {
    auto data = alloc_n_copy(s.begin(), s.end());
    free();
    first = data.first;
    last = cap = data.second;
    return *this;
}
std::ostream &operator<<(std::ostream &os, const String &s) {
    auto p = s.first;
    while (p != s.last) {
        os << *p;
        ++p;
    }
    return os;
}
std::pair<char *, char *> String::alloc_n_copy(const char *begin, const char *end) {
    auto data = alloc.allocate(end - begin);
    return {data, std::uninitialized_copy(begin, end, data)};
}

void String::free() {
    if (first) {
        for (auto p = last; p != first;)
            alloc.destroy(--p);
        alloc.deallocate(first, cap - first);
    }
}


int main(int argc, char const *argv[]) {
    char c[] = "Hello,world!";
    String s1(c);
    std::cout << s1 << std::endl;
    return 0;
}
