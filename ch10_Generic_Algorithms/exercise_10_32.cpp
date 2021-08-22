/*
 * 重写1.6节（第21页）的书店程序，
 * 使用一个vector保存交易记录，使用不同的算法完成处理。
 * 使用sort和10.3.1节（第345页）中的compareIsbn函数来排序交易记录，然后使用find和accumulate求和。
 */

#include "Sales_item.h"
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

// Salas_item.h 内含一个无法排序的compareIsbn函数
bool compareISBN(const Sales_item &lhs, const Sales_item &rhs) { return lhs.isbn() < rhs.isbn(); }


int main(int argc, char const *argv[]) {
    if (argc < 2) exit(1);
    std::ifstream file(argv[1], std::fstream::in);
    if (!file) exit(1);
    std::istream_iterator<Sales_item> book_in(file), end;
    std::vector<Sales_item> data(book_in, end);
    file.close();
    std::sort(data.begin(), data.end(), compareISBN);
    auto begin = data.begin();
    std::vector<Sales_item> result;
    while (begin != data.end()) {
        auto end = std::find_if(begin, data.end(), [begin](const Sales_item &a) { return a.isbn() != begin->isbn(); });
        Sales_item init(begin->isbn());
        result.push_back(std::accumulate(begin, end, init));
        begin = end;
    }
    for (const auto &book : result) {
        std::cout << book << std::endl;
    }
    return 0;
}
