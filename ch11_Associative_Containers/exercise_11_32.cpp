/*
 * 使用上一题定义的multimap编写一个程序，
 * 按字典序打印作者列表和他们的作品。
 */

#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

int main(int argc, char const *argv[]) {
    if (argc < 2) exit(1);
    std::fstream file(argv[1], std::fstream::in);
    if (!file) exit(1);
    std::multimap<std::string, std::string> authors;
    std::string line;
    while (getline(file, line)) {
        std::istringstream record(line);
        std::string author, book;
        record >> author;
        record >> book;
        authors.emplace(std::make_pair(author, book));
    }
    for (const auto &a : authors)
        std::cout << a.first << " "
                  << a.second << std::endl;
    return 0;
}
