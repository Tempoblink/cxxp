/*
 * 上题的这个类还需要定义其他赋值运算符吗？
 * 如果是，请实现它们；同时说明运算对象应该是什么类型并解释原因。
 */

/*
 * 不需要。
 */

#include <iostream>
#include <string>

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

int main(void) {
    Book b2("C++ primer", "Stanly B.Lippman", "2013.09.01");
    Book b1("C++ primer plus", "Stanly B.Lippman", "2013.09.01");
    std::cout << std::boolalpha << (b2 < b1) << std::endl;
    return 0;
}
