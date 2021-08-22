/*
 * 编写你自己的Basket类，用它计算上一个练习中交易记录的总价格。
 */

#include "include/Basket.h"
#include "include/Bulk_quote.h"
#include <iostream>
#include <memory>

int main(int argc, char const *argv[]) {
    Basket bk;
    bk.add_item(std::make_shared<Quote>("0-201-82470-1", 50));
    bk.add_item(Quote("0-201-82470-1", 50));
    bk.add_item(Quote("0-201-82470-1", 50));
    bk.add_item(std::make_shared<Bulk_quote>("0-201-82470-2", 20, 3, .25));
    bk.add_item(Bulk_quote("0-201-82470-2", 20, 3, .25));
    bk.add_item(Bulk_quote("0-201-82470-2", 20, 3, .25));
    bk.total_receipt(std::cout);
    return 0;
}
