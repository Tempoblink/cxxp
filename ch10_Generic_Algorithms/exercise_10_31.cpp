/*
 * 修改前一题的程序，使其只打印不重复的元素。
 * 你的程序应使用unique_copy（参见10.4.1节，第359页）。
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
    std::unique_copy(tmp.cbegin(), tmp.cend(), int_out);
    std::cout << std::endl;
    return 0;
}
