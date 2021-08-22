#include "Sales_data.h"

std::ostream &operator<<(std::ostream &os, const Sales_data &book) {
    double price = book.units_sold ? book.revenue / book.units_sold : 0;
    os << book.bookNo << '\t'
       << book.units_sold << '\t'
       << price << '\t'
       << book.revenue;
    return os;
}
std::istream &operator>>(std::istream &is, Sales_data &book) {
    double price = 0.0;
    is >> book.bookNo >> book.units_sold >> price;
    book.revenue = book.units_sold * price;
    return is;
}
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}
bool operator<(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.bookNo < rhs.bookNo;
}
bool operator>(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.bookNo > rhs.bookNo;
}
bool operator==(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.bookNo == rhs.bookNo;
}
bool operator!=(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.bookNo != rhs.bookNo;
}
Sales_data &Sales_data::operator=(Sales_data s) {
    swap(*this, s);
    return *this;
}
Sales_data &Sales_data::operator=(const std::string &name) {
    *this = Sales_data(name);
    return *this;
}
Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
    combine(rhs);
    return *this;
}
void Sales_data::swap(Sales_data &lhs, Sales_data &rhs) {
    using std::swap;
    swap(lhs.bookNo, rhs.bookNo);
    swap(lhs.units_sold, rhs.units_sold);
    swap(lhs.revenue, rhs.revenue);
}
Sales_data &Sales_data::combine(const Sales_data &book) {
    if (*this == book) {
        units_sold += book.units_sold;
        revenue += book.revenue;
    }
    return *this;
}
