#pragma once

#include <initializer_list>
#include <string>
#include <vector>
#include <iostream>

class StrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;
    friend bool operator==(const StrBlob &, const StrBlob &);
    friend bool operator!=(const StrBlob &, const StrBlob &);
    friend bool operator<(const StrBlob &, const StrBlob &);

public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    std::string &operator[](std::size_t);
    const std::string &operator[](std::size_t) const;
    //增删
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();
    //查
    std::string &front();
    std::string &back();
    StrBlobPtr begin();
    StrBlobPtr end();

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};
