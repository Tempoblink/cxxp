/*
 * 从下面的抽象概念中选择一个（或者你自己指定一个），
 * 思考这样的类需要哪些数据成员，提供一组合理的构造函数并阐明这样做的原因。
 */

#include <iostream>
#include <string>

class Book {
    friend std::ostream &print(std::ostream &os, const Book &book);

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

std::ostream &print(std::ostream &os, const Book &book) {
    os << book.m_name << " "
       << book.m_auther << " "
       << book.m_pubdate << std::endl;
    return os;
}

int main(void) {
    Book b1;
    print(std::cout, b1);

    Book b2("C++ primer", "Stanly B.Lippman", "2013.09.01");
    print(std::cout, b2);

    Book b3(std::cin);
    print(std::cout, b3);
    return 0;
}
