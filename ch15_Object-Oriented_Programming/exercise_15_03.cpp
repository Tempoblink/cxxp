/*
 * 定义你自己的Quote类和print_total函数。
 */

#include "include/Quote.h"
#include <iostream>

double print_total(std::ostream &os, const Quote &item, std::size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

int main(int argc, char const *argv[]) {
    Quote q1("0-021-78345-X", 20.0);
    print_total(std::cout, q1, 5);
    return 0;
}
