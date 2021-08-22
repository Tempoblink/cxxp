/*
 * 定义一个类使其实现一种数量受限的折扣策略，具体策略是：
 * 当购买书籍的数量不超过一个给定的限量时享受折扣，
 * 如果购买量一旦超过了限量，则超出的部分将以原价销售。
 */

#include "include/Quote.h"
#include <iostream>

class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, const double &price, const std::size_t &max_count, const double &discount) : Quote(book, price), _max_count(max_count), _discount(discount) {}
    double net_price(const std::size_t &) const override;

private:
    std::size_t _max_count = 0;
    double _discount = 0.0;
};

double Bulk_quote::net_price(const std::size_t &n) const {
    if (n <= _max_count)
        return n * (1 - _discount) * price;
    else
        return (n - _max_count * _discount) * price;
}

double print_total(std::ostream &os, const Quote &item, std::size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
       << " # sold: " << n
       << " total due: " << ret << std::endl;
    return ret;
}

int main(int argc, char const *argv[]) {
    Bulk_quote b1("0-201-78345-X", 25, 10, 0.2);
    print_total(std::cout, b1, 8);
    print_total(std::cout, b1, 18);
    return 0;
}
