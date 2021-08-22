/*
 * 编写程序，定义一个作者及其作品的multimap。
 * 使用find在multimap中查找一个元素并用erase删除它。
 * 确保你的程序在元素不在map中时也能正常运行。
 */


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

    auto iter = authors.find("Lippman");
    if (iter != authors.cend())
        authors.erase(iter);

    std::cout << std::endl;
    for (const auto &a : authors)
        std::cout << a.first << " "
                  << a.second << std::endl;
    return 0;
}
