/*
 * 使用istream构造函数重写第229页的程序。
 */

#include <iostream>
#include <string>

struct Sales_data;
std::istream &read(std::istream &is, Sales_data &book);

struct Sales_data {
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p) {}
    Sales_data(std::istream &is) {
        read(is, *this);
    }

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


std::ostream &print(std::ostream &os, const Sales_data &book) {
    os << book.bookNo << " "
       << book.units_sold << " "
       << book.revenue << " "
       << (book.units_sold ? book.avg_price() : 0.0)
       << std::endl;
    return os;
}

int main(void) {
    Sales_data total(std::cin);
    if (std::cin) {
        while (true) {
            Sales_data trans(std::cin);
            if (!std::cin) break;
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(std::cout, total);
                total = trans;
            }
        }
        print(std::cout, total);
    } else {
        std::cerr << "No data?" << std::endl;
    }
    return 0;
}
