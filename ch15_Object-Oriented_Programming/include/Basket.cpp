#include "Basket.h"


double print_total(std::ostream &os, const Quote &item, std::size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

double Basket::total_receipt(std::ostream &os) const {
    double sum = 0.0;
    // item -> multiset
    for (auto iter = items.begin(); iter != items.end(); iter = items.upper_bound(*iter)) {
        //count 计算数量
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total Sale: " << sum << std::endl;
    return sum;
}
