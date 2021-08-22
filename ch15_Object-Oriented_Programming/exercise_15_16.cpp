/*
 * 改写你在15.2.2节（第533页）练习中编写的数量受限的折扣策略，
 * 令其继承Disc_quote。
 */

#include "include/Disc_quote.h"

int main(int argc, char const *argv[]) {
    Bulk_quote b1("0-201-78345-X", 25, 10, 0.2);
    std::cout << "quantity:  5, total: " << b1.net_price(5) << std::endl;
    std::cout << "quantity: 15, total: " << b1.net_price(15) << std::endl;
    return 0;
}
