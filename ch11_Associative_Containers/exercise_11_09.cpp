/*
 * 定义一个map，将单词与一个行号的list关联，list中保存的是单词所出现的行号。
 */

#include <fstream>
#include <iostream>
#include <istream>
#include <list>
#include <map>
#include <sstream>
#include <string>

int main(int argc, char const *argv[]) {
    if (argc < 2) exit(1);
    std::fstream file(argv[1], std::fstream::in);
    if (!file) exit(1);

    std::map<std::string, std::list<int>> imap;
    std::string line;
    int count = 1;
    while (getline(file, line)) {
        std::istringstream record(line);
        std::string word;
        while (record >> word) {
            imap[word].push_back(count);
        }
        ++count;
    }

    for (const auto &word : imap) {
        std::cout << "The word: " << word.first
                  << " at ";
        for (const auto &i : word.second) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
