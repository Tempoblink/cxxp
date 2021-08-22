/*
 * 定义你自己的Disc_quote和Bulk_quote。
 */

#include "include/Disc_quote.h"


int main(int argc, char const *argv[]) {
    Bulk_quote t1("0-201-78345-X", 25.0, 20, 0.8);
    std::cout << "---------Bulk_quote--------" << std::endl;
    t1.debug();
    return 0;
}
