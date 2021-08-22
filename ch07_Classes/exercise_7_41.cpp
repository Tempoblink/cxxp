/*
 * 使用委托构造函数重新编写你的Sales_data类，
 * 给每个构造函数体添加一条语句，令其一旦执行就打印一条信息。
 * 用各种可能的方式分别创建Sales_data对象，
 * 认真研究每次输出的信息直到你确实理解了委托构造函数的执行顺序。
 */

#include <iostream>
#include <string>

struct Sales_data {
    friend std::istream &read(std::istream &is, Sales_data &book);
    friend std::ostream &print(std::ostream &os, const Sales_data &book);

public:
    Sales_data(std::string bookNo, unsigned units_sold, double revenue) : m_bookNo(bookNo), m_units_sold(units_sold), m_revenue(revenue) {
        std::cout << "This is a three parameter constructor." << std::endl;
        print(std::cout, *this);
    }

    Sales_data() : Sales_data("", 0, 0.0) {
        std::cout << "This is default constructor." << std::endl;
        print(std::cout, *this);
    }
    Sales_data(std::string bookNo) : Sales_data(bookNo, 0, 0.0) { print(std::cout, *this); }
    Sales_data(std::istream &is) : Sales_data() {
        read(is, *this);
        print(std::cout, *this);
    }

private:
    std::string m_bookNo;
    unsigned m_units_sold = 0;
    double m_revenue = 0.0;
};

std::istream &read(std::istream &is, Sales_data &book) {
    double price = 0.0;
    is >> book.m_bookNo >> book.m_units_sold >> price;
    book.m_revenue = book.m_units_sold * price;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &book) {
    os << book.m_bookNo << " "
       << book.m_units_sold << " "
       << book.m_revenue << std::endl;
    return os;
}

int main(void) {
    Sales_data b1(std::cin);
    print(std::cout, b1);
    return 0;
}
