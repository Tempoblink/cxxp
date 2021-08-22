/*
 * 为你的Sales_data类定义输出运算符。
 */

#include "include/Sales_data.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

int main(int argc, char const *argv[]) {
    if (argc < 2) exit(1);
    std::fstream file(argv[1], std::fstream::in);
    if (!file) exit(1);
    std::istream_iterator<Sales_data> read(file), eof;
    std::vector<Sales_data> data(read, eof);
    std::cout << "--------------book list--------------" << std::endl;
    for (const auto &book : data) {
        std::cout << book << std::endl;
    }
    return 0;
}
