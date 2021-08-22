#include "Disc_quote.h"

double Bulk_quote::net_price(const std::size_t &n) const {
    if (n <= quantity)
        return n * (1 - discount) * price;
    else
        return (n - quantity * discount) * price;
}

void Bulk_quote::debug(std::ostream &os) const {
    Quote::debug();
    os << "quantity: " << quantity << '\n'
       << "discount: " << discount << '\n';
}
