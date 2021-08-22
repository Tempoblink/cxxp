/*
 * 编写名为compareIsbn的函数，比较两个Sales_data对象的isbn()成员。
 * 使用这个函数排序一个保存Sales_data对象的vector。
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

bool compareIsbn(const Sales_data &book1, const Sales_data &book2) {
    return book1.isbn() < book2.isbn();
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
    print(vec_sale);
    std::stable_sort(vec_sale.begin(), vec_sale.end(), compareIsbn);
    print(vec_sale);
    return 0;
}
