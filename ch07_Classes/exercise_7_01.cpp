/*
 * 使用2.6.1节练习定义的Sales_data类为1.6节（第21页）的交易处理程序编写一个新版本。
 */

#include <iostream>
#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

std::istream &read(std::istream &is, Sales_data &book) {
    double price = 0.0;
    is >> book.bookNo >> book.units_sold >> price;
    book.revenue = book.units_sold * price;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &book) {
    double avg_price = 0.0;
    if (book.units_sold)
        avg_price = book.revenue / book.units_sold;

    os << book.bookNo << " "
       << book.units_sold << " "
       << book.revenue << " "
       << avg_price << std::endl;
    return os;
}

void combine(Sales_data &book1, Sales_data &book2) {
    if (book1.bookNo != book2.bookNo)
        return;
    book1.units_sold += book2.units_sold;
    book1.revenue += book2.revenue;
}

int main(void) {
    Sales_data total;
    if (read(std::cin, total)) {
        Sales_data trans;
        while (read(std::cin, trans)) {
            if (total.bookNo == trans.bookNo) {
                combine(total, trans);
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
