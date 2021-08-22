/*
 * 定义一个存放Quote对象的vector，将Bulk_quote对象传入其中，计算vector中所有元素总的net_price。
 */

#include "include/Bulk_quote.h"
#include "include/Quote.h"
#include <algorithm>
#include <memory>
#include <vector>

int main(int argc, char const *argv[]) {
    std::vector<std::shared_ptr<Quote>> qvec;
    qvec.push_back(std::make_shared<Bulk_quote>("0-201-54848-8", 50, 10, .25));
    qvec.push_back(std::make_shared<Bulk_quote>("0-201-54848-8", 50, 20, .25));
    qvec.push_back(std::make_shared<Bulk_quote>("0-201-54848-8", 50, 30, .25));
    qvec.push_back(std::make_shared<Bulk_quote>("0-201-54848-8", 50, 40, .25));
    qvec.push_back(std::make_shared<Bulk_quote>("0-201-54848-8", 50, 50, .25));
    std::for_each(qvec.begin(), qvec.end(), [](const std::shared_ptr<Quote> &p) { std::cout << p->net_price(30) << std::endl; });
    return 0;
}
