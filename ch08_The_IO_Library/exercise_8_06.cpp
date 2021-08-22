/*
 * 重写7.1.1节的书店程序（第229页），从一个文件中读取交易记录。
 * 将文件名作为一个参数传递给main（参见6.2.5节，第196页）。
 */

#include <fstream>
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

int main(int argc, char const *argv[]) {
    if (argc < 2) exit(1);
    std::ifstream fs(argv[1], std::ios::in);
    if (!fs) exit(1);
    Sales_data total;
    if (read(fs, total)) {
        Sales_data trans;
        while (read(fs, trans)) {
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
    fs.close();
    return 0;
}
