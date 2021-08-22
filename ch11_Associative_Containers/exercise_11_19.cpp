/*
 * 定义一个变量，通过对11.2.2节（第378页）中的名为bookstore的multiset调用begin()来初始化这个变量。
 * 写出变量的类型，不要使用auto或decltype。
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
    std::multiset<Sales_item, func>::iterator iter = bookstore.begin();
    return 0;
}
