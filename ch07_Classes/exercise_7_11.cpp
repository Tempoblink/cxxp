/*
 * 在你的Sales_data类中添加构造函数，然后编写一段程序令其用到每个构造函数。
 */

#include <iostream>
#include <string>

struct Sales_data {
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p) {}
    Sales_data(std::istream &);

    //api
    Sales_data &combine(const Sales_data &);
    std::string isbn() const { return bookNo; }
    double avg_price() const;

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data &Sales_data::combine(const Sales_data &book) {
    units_sold += book.units_sold;
    revenue += book.revenue;
    return *this;
}

double Sales_data::avg_price() const {
    return revenue / units_sold;
}

Sales_data add(const Sales_data &book1, const Sales_data &book2) {
    Sales_data sum = book1;
    sum.combine(book2);
    return sum;
}

std::istream &read(std::istream &is, Sales_data &book) {
    double price = 0.0;
    is >> book.bookNo >> book.units_sold >> price;
    book.revenue = book.units_sold * price;
    return is;
}

Sales_data::Sales_data(std::istream &is) {
    read(is, *this);
}

std::ostream &print(std::ostream &os, const Sales_data &book) {
    os << book.bookNo << " "
       << book.units_sold << " "
       << book.revenue << " "
       << (book.units_sold ? book.avg_price() : 0.0)
       << std::endl;
    return os;
}

int main(void) {
    Sales_data book1;
    print(std::cout, book1);

    Sales_data book2("0-201-70353-X");
    print(std::cout, book2);

    Sales_data book3("0-201-70353-X", 2, 20);
    print(std::cout, book3);

    Sales_data book4(std::cin);
    print(std::cout, book4);

    return 0;
}
