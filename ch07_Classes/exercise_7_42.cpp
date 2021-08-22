/*
 * 对于你在练习7.40（参见7.5.1节，第261页）中编写的类，
 * 确定哪些构造函数可以使用委托。
 * 如果可以的话，编写委托构造函数。
 * 如果不可以，从抽象概念列表中重新选择一个你认为可以使用委托构造函数的，为挑选出的这个概念编写类定义。
 */


#include <iostream>
#include <string>

class Book {
    friend std::ostream &print(std::ostream &os, const Book &book);

public:
    Book(std::string name, std::string auther, std::string pubdate) : m_name(name), m_auther(auther), m_pubdate(pubdate) {}
    Book() = default;
    Book(std::istream &is) : Book() {
        is >> m_name >> m_auther >> m_pubdate;
    }

private:
    std::string m_name;
    std::string m_auther;
    std::string m_pubdate;
};

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
