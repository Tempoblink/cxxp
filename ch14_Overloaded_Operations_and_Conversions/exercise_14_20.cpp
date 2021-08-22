/*
 * 为你的Sales_data类定义加法和复合赋值运算符。
 */

#include "include/Sales_data.h"
#include <fstream>
#include <vector>
#include <iostream>

int main(int argc, char const *argv[]) {
    if (argc < 2) exit(1);
    std::fstream file(argv[1], std::fstream::in);
    if (!file) exit(1);
    std::istream_iterator<Sales_data> read(file), eof;
    std::vector<Sales_data> data(read, eof);
    std::vector<Sales_data> result;
    std::sort(data.begin(), data.end());
    auto end = data.begin();
    while (end != data.end()) {
        auto begin = end;
        Sales_data trans(begin->isbn());
        while (*end == *begin) {
            trans += *end;
            ++end;
        }
        result.push_back(trans);
        begin = end;
    }
    std::for_each(result.begin(), result.end(), [](const Sales_data &s) { std::cout << s << std::endl; });

    return 0;
}
