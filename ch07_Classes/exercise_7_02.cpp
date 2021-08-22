/*
 * 曾在2.6.2的练习（第67页）中编写了一个Sales_data类，请向这个类添加combine和isbn成员。
 */

#include <iostream>
#include <string>

struct Sales_data {
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
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

int main(void) {
    return 0;
}
