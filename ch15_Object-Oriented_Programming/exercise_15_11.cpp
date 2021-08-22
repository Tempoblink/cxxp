/*
 * 为你的Quote类体系添加一个名为debug的虚函数，令其分别显示每个类的数据成员。
 */

#include "include/Bulk_quote.h"
#include "include/Quote.h"

int main(int argc, char const *argv[]) {
    Quote q1("0-201-78345-X", 25.00);
    Bulk_quote b1("0-201-78345-X", 25.00, 20, 0.2);
    std::cout << "---------q1.debug---------" << std::endl, q1.debug();
    std::cout << "---------q2.debug---------" << std::endl, b1.debug();
    return 0;
}
