/*
 * 使用list代替vector重新实现10.2.3节（第343页）中的去除重复单词的程序。
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <string>

void elimDups(std::list<std::string> &words) {
    words.sort();
    words.unique();
}

int main(int argc, char const *argv[]) {
    if (argc < 2) exit(1);
    std::fstream file(argv[1], std::fstream::in);
    if (!file) exit(1);
    std::istream_iterator<std::string> read(file), end_read;
    std::list<std::string> words(read, end_read);
    elimDups(words);
    std::ostream_iterator<std::string> print(std::cout, " ");
    copy(words.begin(), words.end(), print);
    std::cout << std::endl;
    return 0;
}
