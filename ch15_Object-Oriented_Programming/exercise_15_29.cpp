/*
 * 再运行一次你的程序，这次传入Quote对象的shared_ptr。
 * 如果这次计算出的总额与之前的程序不一致，解释为什么；
 * 如果一致，也请说明原因。
 */

/*
 * 这次的计算结果不一致。
 * 因为上个版本虽然传入的是Bulk_quote，但实际上vector里面插入的仍然是Quote对象；
 * 而这个版本，vector中存放的是Quote的智能指针，它可以动态绑定到Bulk_quote类型的对象上面。
 */

#include "include/Bulk_quote.h"
#include "include/Quote.h"
#include <algorithm>
#include <memory>
#include <vector>

int main(int argc, char const *argv[]) {
    std::vector<std::shared_ptr<Quote>> qvec;
    qvec.push_back(std::make_shared<Quote>("0-201-54848-8", 50));
    qvec.push_back(std::make_shared<Quote>("0-201-54848-8", 40));
    qvec.push_back(std::make_shared<Quote>("0-201-54848-8", 30));
    qvec.push_back(std::make_shared<Quote>("0-201-54848-8", 20));
    qvec.push_back(std::make_shared<Quote>("0-201-54848-8", 10));
    std::for_each(qvec.begin(), qvec.end(), [](const std::shared_ptr<Quote> &p) { std::cout << p->net_price(30) << std::endl; });
    return 0;
}
