#pragma once

#include "Quote.h"
#include <cstddef>
#include <string>

class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double price, std::size_t qty, double disc) : Quote(book, price), quantity(qty), discount(disc) {
        std::cout << "Disc_quote(const string&, double, size_t, dobule)" << std::endl;
    }
    double net_price(const std::size_t &) const = 0;

protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};


class Bulk_quote : public Disc_quote {
public:
    using Disc_quote::Disc_quote;
    Bulk_quote() = default;
    // Bulk_quote(const std::string &book, double price, std::size_t qty, double disc) : Disc_quote(book, price, qty, disc) {}
    double net_price(const std::size_t &n) const override;
    void debug(std::ostream &os = std::cout) const override;
};
