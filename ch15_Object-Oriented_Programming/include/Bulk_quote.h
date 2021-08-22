#pragma once

#include "Quote.h"
#include <cstddef>
#include <iostream>
#include <memory>

class Bulk_quote : public Quote {
public:
    Bulk_quote() { std::cout << "Bulk_quote()" << std::endl; }
    Bulk_quote(const std::string &, double, std::size_t, double);
    Bulk_quote(const Bulk_quote &b) : Quote(b), min_qty(b.min_qty), discount(b.discount) {
        std::cout << "Bulk_quote(const Bulk_quote &)" << std::endl;
    }
    Bulk_quote(Bulk_quote &&b) : Quote(std::move(b)), min_qty(std::move(b.min_qty)), discount(std::move(b.discount)) {
        std::cout << "Bulk_quote(Bulk_quote &&)" << std::endl;
    }
    Bulk_quote &operator=(const Bulk_quote &);
    Bulk_quote &operator=(Bulk_quote &&);
    ~Bulk_quote() { std::cout << "~Bulk_quote()" << std::endl; }
    Bulk_quote *clone() const & override { return new Bulk_quote(*this); }
    Bulk_quote *clone() && override { return new Bulk_quote(std::move(*this)); }

    double net_price(const std::size_t &) const override;
    void debug(std::ostream &os = std::cout) const override;

private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};
