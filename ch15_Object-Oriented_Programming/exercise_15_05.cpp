/*
 * 定义你自己的Bulk_quote类。
 */

#include "include/Bulk_quote.h"

int main(int argc, char const *argv[]) {
    Bulk_quote t1("0-201-78345-X", 25.0, 20, 0.8);
    auto sum = t1.net_price(30);
    std::cout << sum << std::endl;
    return 0;
}
