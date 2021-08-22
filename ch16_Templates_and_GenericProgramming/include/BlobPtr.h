#pragma once
#include "Blob.h"

template<typename T>
class BlobPtr {
public:
    BlobPtr() : curr(0) {}
    BlobPtr(Blob<T> &a, const std::size_t &sz = 0) : wptr(a.data), curr(sz) {}
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
inline std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound BlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
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
