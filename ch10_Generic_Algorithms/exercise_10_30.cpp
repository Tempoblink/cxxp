/*
 * 使用流迭代器、sort和copy从标准输入读取一个整数序列，
 * 将其排序，并将结果写到标准输出。
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main(int argc, char const *argv[]) {
    std::istream_iterator<int> int_in(std::cin), int_eof;
    std::ostream_iterator<int> int_out(std::cout, " ");

    std::vector<int> tmp(int_in, int_eof);
    std::sort(tmp.begin(), tmp.end());
    std::copy(tmp.cbegin(), tmp.cend(), int_out);
    std::cout << std::endl;
    return 0;
}
