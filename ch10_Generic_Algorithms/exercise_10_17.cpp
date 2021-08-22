/*
 * 重写10.3.1节练习10.12（第345页）的程序，
 * 在对sort的调用中使用lambda来替代函数compareIsbn。
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

class Sales_data {
    friend Sales_data &read(std::istream &is, Sales_data &s);
    friend void print(std::ostream &os, const Sales_data &s);

public:
    Sales_data() = default;
    Sales_data(const std::string &b) : bookNo(b) {}
    Sales_data(const std::string &b, const unsigned u, const double r)
        : bookNo(b), units_sold(u), revenue(r) {}
    std::string isbn() const { return bookNo; }
    double avg_price() const { return revenue / units_sold; }

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data &read(std::istream &is, Sales_data &s) {
    double price = 0.0;
    is >> s.bookNo >> s.units_sold >> price;
    s.revenue = s.units_sold * price;
    return s;
}
void print(std::ostream &os, const Sales_data &s) {
    double price;
    if (s.units_sold) {
        price = s.avg_price();
    }
    os << "bookNo = " << s.bookNo << "\tunits_sold = " << s.units_sold
       << "\tprice = " << price << "\trevenue = " << s.revenue << std::endl;
}

void print(const std::vector<Sales_data> &vec) {
    for (auto book : vec)
        print(std::cout, book);
    std::cout << std::endl;
}

int main(int argc, char const *argv[]) {
    if (argc < 2)
        exit(1);
    std::fstream file(argv[1], std::fstream::in);
    if (!file)
        exit(1);
    std::string info;
    std::vector<Sales_data> vec_sale;
    while (getline(file, info)) {
        std::istringstream record(info);
        Sales_data trans;
        read(record, trans);
        vec_sale.push_back(trans);
    }
    std::stable_sort(vec_sale.begin(), vec_sale.end(),
                     [](const Sales_data &a, const Sales_data &b) {
                         return a.isbn() < b.isbn();
                     });
    print(vec_sale);
    return 0;
}
