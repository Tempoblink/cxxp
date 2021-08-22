/*
 * 将Sales_data::avg_price定义成内联函数。
 */

#include <iostream>
#include <string>

struct Sales_data {
public:
    Sales_data() = default;
    //类内初始值显示初始化成员 units_sold 和 revenue。
    Sales_data(const std::string &s) : bookNo(s), units_sold(0), revenue(0.0) {}
    //类内初始值隐示初始化成员 units_sold 和 revenue。
    //Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p) {}
    Sales_data(std::istream &);

    //api
    Sales_data &combine(const Sales_data &);
    std::string isbn() const { return bookNo; }

    friend std::istream &read(std::istream &is, Sales_data &book);
    friend std::ostream &print(std::ostream &os, const Sales_data &book);

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    double avg_price() const;
};

Sales_data &Sales_data::combine(const Sales_data &book) {
    units_sold += book.units_sold;
    revenue += book.revenue;
    return *this;
}

inline double Sales_data::avg_price() const {
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
    return 0;
}
