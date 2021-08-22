/*
 * 为你的StrVec类及你为16.1.2节（第591页）练习中编写的Vec类添加emplace_back函数。
 */

#include <initializer_list>
#include <iostream>
#include <memory>
#include <string>
#include <utility>

template<typename T>
class Vec;

template<typename T>
bool operator==(const Vec<T> &, const Vec<T> &);

template<typename T>
bool operator!=(const Vec<T> &, const Vec<T> &);

template<typename T>
bool operator<(const Vec<T> &, const Vec<T> &);

template<typename T>
class Vec {
    friend bool operator==<T>(const Vec &, const Vec &);
    friend bool operator!=<T>(const Vec &, const Vec &);
    friend bool operator< <T>(const Vec &, const Vec &);

public:
    typedef T value_type;
    Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    Vec(const Vec &);
    Vec(Vec &&);
    void swap(Vec &, Vec &);
    Vec &operator=(Vec);
    Vec(const std::initializer_list<T> &li);
    ~Vec() { free(); }
    void push_back(const T &t) {
        chk_n_alloc();
        alloc.construct(first_free++, t);
    }

    template<typename... Args>
    void emplace_back(Args &&...);

    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    T *begin() const { return elements; }
    T *end() const { return first_free; }

private:
    static std::allocator<T> alloc;
    void chk_n_alloc() {
        if (size() == capacity())
            reallocate();
    }
    std::pair<T *, T *> alloc_n_copy(const T *, const T *);
    void reallocate();
    void free();
    T *elements;
    T *first_free;
    T *cap;
};

template<typename T>
std::allocator<T> Vec<T>::alloc;

template<typename T>
inline std::pair<T *, T *> Vec<T>::alloc_n_copy(const T *first, const T *end) {
    auto data = alloc.allocate(end - first);
    return {data, std::uninitialized_copy(first, end, data)};
}
template<typename T>
inline void Vec<T>::free() {
    if (elements) {
        for (auto p = first_free; p != elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

template<typename T>
inline void Vec<T>::reallocate() {
    auto newcap = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcap);
    auto dest = newdata, elem = elements;
    for (size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcap;
}

template<typename T>
inline Vec<T>::Vec(const Vec &v) {
    auto newdata = alloc_n_copy(v.begin(), v.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

template<typename T>
inline Vec<T>::Vec(Vec &&v) : elements(v.elements), first_free(v.first_free), cap(v.cap) {
    v.elements = v.first_free = v.cap = nullptr;
}

template<typename T>
void Vec<T>::swap(Vec &lhs, Vec &rhs) {
    using std::swap;
    swap(lhs.elements, rhs.elements);
    swap(lhs.first_free, rhs.first_free);
    swap(lhs.cap, rhs.cap);
}

template<typename T>
Vec<T> &Vec<T>::operator=(Vec v) {
    swap(*this, v);
    return *this;
}

template<typename T>
Vec<T>::Vec(const std::initializer_list<T> &li) {
    auto newdata = alloc_n_copy(li.begin(), li.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

template<typename T>
bool operator==(const Vec<T> &lhs, const Vec<T> &rhs) {
    auto l = lhs.elements, r = rhs.elements;
    for (; l != lhs.end() && r != rhs.end(); ++l, ++r)
        if (*l != *r) return false;
    if (l == lhs.end() && r == rhs.end())
        return true;
    else
        return false;
}

template<typename T>
bool operator!=(const Vec<T> &lhs, const Vec<T> &rhs) {
    return !(lhs == rhs);
}

template<typename T>
bool operator<(const Vec<T> &lhs, const Vec<T> &rhs) {
    auto l = lhs.elements, r = rhs.elements;
    for (; l != lhs.end() && r != rhs.end(); ++l, ++r) {
        if (*l > *r)
            return false;
        else if (*l < *r)
            return true;
    }
    if (l == lhs.end() && r < lhs.end())
        return true;
    else
        return false;
}

template<typename T>
template<typename... Args>
void Vec<T>::emplace_back(Args &&...rest) {
    chk_n_alloc();
    alloc.construct(first_free++, std::forward<Args>(rest)...);
}


int main(int argc, char const *argv[]) {
    Vec<int> ivec{1, 2, 3, 4, 5};
    ivec.emplace_back(10);
    for (const auto &i : ivec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    Vec<std::string> svec;
    svec.emplace_back(10, 'c');
    for (const auto &i : svec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
