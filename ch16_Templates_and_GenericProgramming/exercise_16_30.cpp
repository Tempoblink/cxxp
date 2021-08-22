/*
 * 重新运行你的一些程序，验证你的shared_ptr类和修改后的Blob类。
 * （注意：实现weak_ptr类型超出了本书范围，因此你不能将BlobPtr类与你修改后的Blob一起使用。）
 */

#include "include/Shared_Ptr.h"
#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>


template<typename>
class Blob;

template<typename T>
bool operator==(const Blob<T> &, const Blob<T> &);

template<typename T>
class Blob {
    friend bool operator==<T>(const Blob &, const Blob &);

public:
    using value_tpye = T;
    using size_type = typename std::vector<T>::size_type;
    Blob() : data(new std::vector<T>()) {}
    Blob(std::initializer_list<T> il) : data(new std::vector<T>(il.begin(), il.end())) {}
    template<typename It>
    Blob(It, It);

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
    Shared_Ptr<std::vector<T>> data;
    void check(size_type, const std::string &) const;
};

template<typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs) {
    return *lhs.data == *rhs.data;
}

template<typename T>
template<typename It>
Blob<T>::Blob(It b, It e) : data(std::make_shared<std::vector<T>>(b, e)) {
}

template<typename T>
inline void Blob<T>::check(size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
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

int main(int argc, char const *argv[]) {
    Blob<int> ibob{1, 2, 3, 4, 5, 6};
    for (size_t i = 0; i < ibob.size(); ++i)
        std::cout << ibob[i] << std::endl;
    return 0;
}
