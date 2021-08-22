/*
 * 对你在练习13.44（13.5节，第470页）中定义的String类，
 * 为它的拷贝构造函数和拷贝赋值运算符添加一条语句，
 * 在每次函数执行时打印一条信息。
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
    std::cout << "String(const char *)" << std::endl;
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
    std::cout << "operator=(const String &s)" << std::endl;
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
    String s2(s1);
    String s3;
    s3 = s2;

    std::cout << s1 << std::endl;
    return 0;
}
