/*
 * 修改7.1.1节（第229页）的交易处理程序，令其使用这些成员。
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

std::istream &read(std::istream &is, Sales_data &book) {
    double price = 0.0;
    is >> book.bookNo >> book.units_sold >> price;
    book.revenue = book.units_sold * price;
    return is;
}

std::ostream &print(std::ostream &os, Sales_data &book) {
    double avg_price = 0.0;
    if (book.units_sold) {
        avg_price = book.revenue / book.units_sold;
    }
    os << book.bookNo << " "
       << book.units_sold << " "
       << book.revenue << " "
       << avg_price << std::endl;
    return os;
}


int main(void) {
    Sales_data total;
    if (read(std::cin, total)) {
        Sales_data trans;
        while (read(std::cin, trans)) {
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
