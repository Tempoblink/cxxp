/*
 * 定义你自己版本的hash<Sales_data>，并定义一个Sales_data对象的unordered_multiset。
 * 将多条交易记录保存到容器中，并打印其内容。
 */

#include "include/Sales_data.h"
#include <unordered_set>

namespace std {
    template<>
    struct hash<Sales_data> {
        typedef size_t result_type;
        typedef Sales_data argument_type;
        size_t operator()(const Sales_data &) const;
    };

    size_t hash<Sales_data>::operator()(const Sales_data &s) const {
        return hash<string>()(s.bookNo) ^
               hash<unsigned>()(s.units_sold) ^
               hash<double>()(s.revenue);
    }
}// namespace std


int main(int argc, char const *argv[]) {
    std::unordered_set<Sales_data> saet;
    saet.insert(Sales_data("cppprimer"));
    saet.insert(Sales_data("cppprimerplus"));
    for (const auto &i : saet)
        std::cout << i << std::endl;
    return 0;
}
