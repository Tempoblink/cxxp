#pragma once
#include "Bulk_quote.h"
#include "Quote.h"

Bulk_quote::Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) : Quote(book, p), min_qty(qty), discount(disc) {
    std::cout << "Bulk_quote(const string &, double , size_t, double )" << std::endl;
}

double Bulk_quote::net_price(const std::size_t &cnt) const {
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

void Bulk_quote::debug(std::ostream &os) const {
    Quote::debug();
    os << "min_qty: " << min_qty << '\n'
       << "discount: " << discount << '\n';
}

Bulk_quote &Bulk_quote::operator=(const Bulk_quote &b) {
    Quote::operator=(b);
    min_qty = b.min_qty;
    discount = b.discount;
    std::cout << "operator=(const Bulk_quote &)" << std::endl;
    return *this;
}

Bulk_quote &Bulk_quote::operator=(Bulk_quote &&b) {
    Quote::operator=(std::move(b));
    min_qty = std::move(b.min_qty);
    discount = std::move(b.discount);
    std::cout << "operator=(Bulk_quote &&)" << std::endl;
    return *this;
}
