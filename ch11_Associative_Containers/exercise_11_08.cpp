/*
 * 编写一个程序，在一个vector而不是一个set中保存不重复的单词。
 * 使用set的优点是什么？
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
    std::istream_iterator<std::string> read_in(file), read_end;
    std::ostream_iterator<std::string> read_out(std::cout, " ");
    std::vector<std::string> words;
    while (read_in != read_end) {
        if (words.empty() || (std::find(words.cbegin(), words.cend(), *read_in) == words.end()))
            words.push_back(*read_in);
        ++read_in;
    }
    std::cout << "words = ";
    copy(words.cbegin(), words.cend(), read_out);
    std::cout << std::endl;
    return 0;
}
