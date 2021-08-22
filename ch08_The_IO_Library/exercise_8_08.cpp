/*
 * 修改上一题的程序，将结果追加到给定文件末尾。对同一个输出文件，运行程序至少两次，检验数据是否得以保留。
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
    if(argc < 3) exit(1);
    std::ifstream readfile(argv[1], std::ifstream::in);
    if(!readfile) exit(1);
    std::ofstream writefile(argv[2], std::ofstream::app);
    if(!writefile) exit(1);
    Sales_data total;
    if (read(readfile, total)) {
        Sales_data trans;
        while (read(readfile, trans)) {
            if (total.bookNo == trans.bookNo) {
                combine(total, trans);
            } else {
                print(writefile, total);
                total = trans;
            }
        }
        print(writefile, total);
    } else {
        std::cerr << "No data?" << std::endl;
    }
    return 0;
}
