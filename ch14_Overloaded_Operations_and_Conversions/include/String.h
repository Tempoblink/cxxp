#pragma once

#include <algorithm>
#include <iostream>
#include <memory>
#include <utility>

class String {
    friend std::ostream &operator<<(std::ostream &, const String &);
    friend bool operator==(const String &, const String &);
    friend bool operator!=(const String &, const String &);
    friend bool operator<(const String &, const String &);

public:
    String();
    String(const char *);
    String(const String &);
    String(String &&);
    ~String();

    String &operator=(const String &);
    String &operator=(String &&);
    char &operator[](std::size_t);
    char &operator[](std::size_t) const;

    char *begin() const { return first; }
    char *end() const { return last; }
    size_t size() const { return last - first; }

private:
    static std::allocator<char> alloc;

    std::pair<char *, char *> alloc_n_copy(const char *, const char *);
    void free();
    void reallocte();
    void check(std::size_t, const char *) const;
    char *first;
    char *last;
    char *cap;
};
