#pragma once

#include <cstddef>
#include <iostream>
#include <iterator>
#include <string>
#include <memory>

class Quote {
public:
    Quote() { std::cout << "Quote()" << std::endl; }
    Quote(const std::string &book, const double &sales_price) : bookNo(book), price(sales_price) {
        std::cout << "Quote(const string &, const double &)" << std::endl;
    }
    Quote(const Quote &q) : bookNo(q.bookNo), price(q.price) {
        std::cout << "Quote(const Quote &)" << std::endl;
    }
    Quote(Quote &&q) : bookNo(std::move(q.bookNo)), price(std::move(q.price)) {
        std::cout << "Quote(Quote &&)" << std::endl;
    }
    Quote &operator=(const Quote &);
    Quote &operator=(Quote &&);
    virtual ~Quote() { std::cout << "~Quote()" << std::endl; }
    virtual Quote *clone() const & { return new Quote(*this); }
    virtual Quote *clone() && { return new Quote(std::move(*this)); }

    std::string isbn() const { return bookNo; }
    virtual double net_price(const std::size_t &n) const { return n * price; }
    virtual void debug(std::ostream &os = std::cout) const;

private:
    std::string bookNo;

protected:
    double price = 0.0;
};
