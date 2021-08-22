/*
 * 为你的StrVec类添加一个构造函数，它接受一个initializer_list<string>参数。
 */

#include <initializer_list>
#include <iterator>
#include <iostream>
#include <memory>
#include <string>
#include <utility>

class StrVec {

public:
    StrVec();
    StrVec(std::initializer_list<std::string> li);
    StrVec(const StrVec &);
    StrVec &operator=(const StrVec &);
    ~StrVec();

    void push_back(const std::string &);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }

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

StrVec::StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
StrVec::StrVec(std::initializer_list<std::string> li) {
    auto data = alloc_n_copy(li.begin(), li.end());
    elements = data.first;
    first_free = cap = data.second;
}
StrVec::StrVec(const StrVec &s) {
    auto data = alloc_n_copy(s.begin(), s.end());
    elements = data.first;
    first_free = cap = data.second;
}
StrVec &StrVec::operator=(const StrVec &s) {
    auto data = alloc_n_copy(s.begin(), s.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
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

std::allocator<std::string> StrVec::alloc;

int main(int argc, char const *argv[]) {
    StrVec svec{"Hello", "world"};
    std::cout << "svec.capacity = " << svec.capacity() << std::endl;
    std::cout << "svec.size = " << svec.size() << std::endl;
    auto ret = svec.begin();
    while (ret != svec.end()) {
        std::cout << *ret << std::endl;
        ++ret;
    }
    return 0;
}
