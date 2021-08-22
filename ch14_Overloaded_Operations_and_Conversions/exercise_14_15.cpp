/*
 * 你在7.5.1节的练习7.40（第261页）中曾经选择并编写了一个类，
 * 你认为它应该含有其他算术运算符吗？
 * 如果是，请实现它们；如果不是，解释原因。
 */

#include <iostream>
#include <string>

class Book {
    friend std::ostream &operator<<(std::ostream &os, const Book &rhs);
    friend std::istream &operator>>(std::istream &is, Book &rhs);

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

int main(void) {
    Book b2("C++ primer", "Stanly B.Lippman", "2013.09.01");
    std::cout << b2 << std::endl;
    return 0;
}
