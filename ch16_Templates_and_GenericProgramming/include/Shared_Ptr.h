#pragma once

#include <iostream>
#include <sys/_types/_size_t.h>

template<typename T>
class Shared_Ptr {
public:
    Shared_Ptr() : p(nullptr), used(nullptr) {}
    explicit Shared_Ptr(T *q) : p(q), used(new size_t(1)) {}
    Shared_Ptr(const Shared_Ptr &q) : p(q.p), used(q.used) {
        if (used) ++*used;
    }
    Shared_Ptr &operator=(const Shared_Ptr &);
    ~Shared_Ptr();
    void swap(Shared_Ptr &);
    T *get() const { return p; }
    size_t use_count() const { return *used; }
    bool unique() const { return *used == 1; }
    T &operator*() const { return *p; }
    T *operator->() const { return &this->operator*(); }

private:
    T *p;
    size_t *used;
};

template<typename T>
Shared_Ptr<T> &Shared_Ptr<T>::operator=(const Shared_Ptr<T> &rhs) {
    ++*rhs.used;
    if (used && --*used == 0) {
        delete p;
        delete used;
    }
    p = rhs.p;
    used = rhs.used;
    return *this;
}

template<typename T>
Shared_Ptr<T>::~Shared_Ptr<T>() {
    if (used && --*used == 0) {
        delete p;
        delete used;
    }
}

template<typename T>
void Shared_Ptr<T>::swap(Shared_Ptr &rhs) {
    using std::swap;
    swap(p, rhs.p);
    swap(used, rhs.used);
}
