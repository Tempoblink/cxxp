/*
 * 将Quote和Bulk_quote的对象传递给15.2.1节（第529页）练习中的print_total函数，
 * 检查该函数是否正确。
 */

#include "include/Bulk_quote.h"
#include "include/Quote.h"

double print_total(std::ostream &os, const Quote &item, std::size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
       << " # sold: " << n
       << " total due: " << ret << std::endl;
    return ret;
}

int main(int argc, char const *argv[]) {
    Quote q1("0-201-78345-X", 25.00);
    Bulk_quote b1("0-201-78345-X", 25.00, 20, 0.2);
    print_total(std::cout, q1, 30);
    print_total(std::cout, b1, 30);
    return 0;
}
