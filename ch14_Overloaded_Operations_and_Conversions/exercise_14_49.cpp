/*
 * 为上一题提到的类定义一个转换目标是bool的类型转换运算符，先不用在意这么做是否应该。
 */

#include <iostream>
#include <string>
#include <type_traits>

class Book {
    friend std::ostream &operator<<(std::ostream &os, const Book &rhs);
    friend std::istream &operator>>(std::istream &is, Book &rhs);
    friend bool operator==(const Book &, const Book &);
    friend bool operator!=(const Book &, const Book &);
    friend bool operator<(const Book &, const Book &);

public:
    Book() = default;
    Book(std::string name, std::string auther, std::string pubdate) : m_name(name), m_auther(auther), m_pubdate(pubdate) {}
    Book(std::istream &);
    Book(const Book &b) : m_name(b.m_name), m_auther(b.m_auther), m_pubdate(b.m_pubdate) {}
    Book(Book &&b) : m_name(std::move(b.m_name)), m_auther(std::move(b.m_auther)), m_pubdate(std::move(b.m_pubdate)) {
        std::cout << "Book(Book &&)" << std::endl;
    }

    void swap(Book &, Book &);
    Book &operator=(Book);
    explicit operator bool() {
        return !m_name.empty();
    }

private:
    std::string m_name;
    std::string m_auther;
    std::string m_pubdate;
};


Book::Book(std::istream &is) {
    is >> m_name >> m_auther >> m_pubdate;
}

std::ostream &operator<<(std::ostream &os, const Book &book) {
    os << book.m_name << " "
       << book.m_auther << " "
       << book.m_pubdate;
    return os;
}

std::istream &operator>>(std::istream &is, Book &book) {
    is >> book.m_name >> book.m_auther >> book.m_pubdate;
    return is;
}
bool operator==(const Book &lhs, const Book &rhs) {
    return (lhs.m_auther == rhs.m_auther) && (lhs.m_name == rhs.m_name) && (lhs.m_pubdate == lhs.m_pubdate);
}
bool operator!=(const Book &lhs, const Book &rhs) {
    return !(lhs == rhs);
}

bool operator<(const Book &lhs, const Book &rhs) {
    return lhs.m_name < rhs.m_name;
}
void Book::swap(Book &b1, Book &b2) {
    using std::swap;
    swap(b1.m_name, b2.m_name);
    swap(b1.m_auther, b2.m_auther);
    swap(b1.m_pubdate, b2.m_pubdate);
    std::cout << "swap(Book &, Book &)" << std::endl;
}
Book &Book::operator=(Book b) {
    std::cout << "operator=(Book)" << std::endl;
    swap(*this, b);
    return *this;
}

int main(void) {
    Book b1;
    b1 = Book("C++ primer", "Stanly B.Lippman", "2013.09.01");
    Book b2(std::move(b1));
    std::cout << std::boolalpha << static_cast<bool>(b1) << std::endl;
    std::cout << std::boolalpha << static_cast<bool>(b2) << std::endl;
    return 0;
}
