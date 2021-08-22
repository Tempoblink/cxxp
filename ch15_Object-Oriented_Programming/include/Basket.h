#pragma once
#include "Quote.h"
#include <memory>
#include <set>
#include <type_traits>

class Basket {
public:
    void add_item(const std::shared_ptr<Quote> &sale) { items.insert(sale); }
    void add_item(const Quote &q) { items.insert(std::shared_ptr<Quote>(q.clone())); }
    void add_item(Quote &&q) { items.insert(std::shared_ptr<Quote>(std::move(q).clone())); }
    double total_receipt(std::ostream &) const;

private:
    static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs) {
        return lhs->isbn() < rhs->isbn();
    }
    std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare};
};
