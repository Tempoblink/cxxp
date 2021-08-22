#include "Quote.h"
#include <type_traits>

void Quote::debug(std::ostream &os) const {
    os << "bookNo: " << bookNo << '\n'
       << "price: " << price << '\n';
}

Quote &Quote::operator=(const Quote &q) {
    bookNo = q.bookNo;
    price = q.price;
    std::cout << "operator=(const Quote &)" << std::endl;
    return *this;
}

Quote &Quote::operator=(Quote &&q) {
    bookNo = std::move(q.bookNo);
    price = std::move(q.price);
    std::cout << "operator=(Quote &&)" << std::endl;
    return *this;
}
