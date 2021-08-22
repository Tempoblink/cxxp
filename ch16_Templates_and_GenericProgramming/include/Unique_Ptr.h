#pragma once
#include <iostream>

template<typename T>
class Unique_Ptr {
public:
    Unique_Ptr() : q(nullptr) {}
    Unique_Ptr(const Unique_Ptr &) = delete;
    explicit Unique_Ptr(T *p) : q(p) {}
    ~Unique_Ptr();
    Unique_Ptr &operator=(const Unique_Ptr &) = delete;

    void reset(T *newq = nullptr);
    void swap(Unique_Ptr &);
    T *get() const { return q; }
    T &operator*() const { return *q; }
    T *operator->() const { return &this->operator*(); }

private:
    T *q;
};

template<typename T>
Unique_Ptr<T>::~Unique_Ptr() {
    if (q)
        delete q;
}

template<typename T>
void Unique_Ptr<T>::reset(T *newq) {
    if (q)
        delete q;
    q = newq;
}

template<typename T>
void Unique_Ptr<T>::swap(Unique_Ptr<T> &rhs) {
    using std::swap;
    swap(q, rhs.q);
}
