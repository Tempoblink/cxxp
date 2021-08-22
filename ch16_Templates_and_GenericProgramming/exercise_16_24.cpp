/*
 * 为你的Blob模板添加一个构造函数，它接受两个迭代器。
 */

#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <list>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

template<typename T>
class BlobPtr;

template<typename T>
class Blob;

template<typename T>
bool operator==(const Blob<T> &, const Blob<T> &);

template<typename T>
class Blob {
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob &, const Blob &);

public:
    using value_tpye = T;
    using size_type = typename std::vector<T>::size_type;
    Blob() : data(new std::vector<T>()) {}
    Blob(std::initializer_list<T> il) : data(new std::vector<T>(il.begin(), il.end())) {}
    template<typename It>
    Blob(It beg, It end);

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T &t) { data->push_back(t); }
    void pop_back();

    T &back();
    T &front();
    T &operator[](size_type);

    const T &back() const;
    const T &front() const;
    const T &operator[](size_type) const;

private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type, const std::string &) const;
};

template<typename T>
class BlobPtr {
public:
    BlobPtr() : curr(0) {}
    BlobPtr(Blob<T> &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}
    T &operator*() const;
    T *operator->() const;
    BlobPtr &operator++();
    BlobPtr &operator--();

private:
    std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};


template<typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs) {
    return *lhs.data == *rhs.data;
}

template<typename T>
inline T &Blob<T>::back() {
    check(0, "back on empty Blob");
    return data->back();
}

template<typename T>
inline T &Blob<T>::front() {
    check(0, "front on empty Blob");
    return data->front();
}

template<typename T>
inline T &Blob<T>::operator[](size_type i) {
    check(i, "out of range");
    return (*data)[i];
}

template<typename T>
inline const T &Blob<T>::back() const {
    check(0, "back on empty Blob");
    return data->back();
}
template<typename T>
inline const T &Blob<T>::front() const {
    check(0, "front on empty Blob");
    return data->front();
}

template<typename T>
inline const T &Blob<T>::operator[](size_type i) const {
    check(i, "out of range");
    return (*data)[i];
}

template<typename T>
inline void Blob<T>::pop_back() {
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template<typename T>
inline void Blob<T>::check(size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}


template<typename T>
inline T &BlobPtr<T>::operator*() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

template<typename T>
inline T *BlobPtr<T>::operator->() const {
    return &this->operator*();
}

template<typename T>
inline BlobPtr<T> &BlobPtr<T>::operator++() {
    check(curr, "increment past end of BlobPtr");
    ++curr;
    return *this;
}

template<typename T>
inline BlobPtr<T> &BlobPtr<T>::operator--() {
    check(curr, "decrement past begin of BlobPtr");
    --curr;
    return *this;
}

template<typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound BlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

template<typename T>
template<typename It>
Blob<T>::Blob(It beg, It end) : data(std::make_shared<std::vector<T>>(beg, end)) {
}


int main(int argc, char const *argv[]) {
    Blob<int> ib{1, 2, 3, 4, 5, 6};
    Blob<int> ic{1, 2, 3, 4, 5, 6};
    BlobPtr<int> ibptr(ib);
    std::cout << *ibptr << std::endl;
    std::cout << std::boolalpha << (ib == ic) << std::endl;

    std::list<int> ilist{1, 2, 3, 4, 5, 6};
    Blob<int> ia(ilist.begin(), ilist.end());
    return 0;
}
