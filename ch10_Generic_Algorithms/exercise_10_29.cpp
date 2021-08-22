/*
 * 编写程序，使用流迭代器读取一个文本文件，存入一个vector中的string里。
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>


int main(int argc, char const *argv[]) {
    if (argc < 2) exit(1);
    std::fstream file(argv[1], std::fstream::in);
    if (!file) exit(1);
    std::istream_iterator<std::string> str_in(file), str_eof;
    std::vector<std::string> svec(str_in, str_eof);
    std::cout << "svec = ";
    std::for_each(svec.begin(), svec.end(), [](const std::string &s) { std::cout << s << " "; });
    std::cout << std::endl;
    return 0;
}
