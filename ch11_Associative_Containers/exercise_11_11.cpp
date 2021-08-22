/*
 * 不使用decltype重新定义bookstore
 */

#include "Sales_item.h"
#include <iostream>
#include <set>
#include <string>

bool compareISBN(const Sales_item &lhs, const Sales_item &rhs) {
    return lhs.isbn() < rhs.isbn();
}

int main(int argc, char const *argv[]) {
    using func = bool (*)(const Sales_item &, const Sales_item &);
    std::multiset<Sales_item, func> bookstore(compareISBN);
    return 0;
}
