/*
 * 编写程序实现文本查询，不要定义类来管理数据。
 * 你的程序应该接受一个文件，并与用户交互来查询单词。
 * 使用vector、map和set容器来保存来自文件的数据并生成查询结果
 */

#include <fstream>
#include <iostream>
#include <istream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
    if (argc < 2) exit(1);
    std::ifstream file(argv[1], std::ifstream::in);
    if (!file) exit(1);

    using line_no = std::vector<std::string>::size_type;
    std::vector<std::string> lines;
    std::map<std::string, std::set<line_no>> smap;

    std::string line;
    while (getline(file, line)) {
        lines.push_back(line);
        auto cur_line = lines.size() - 1;
        std::istringstream split(line);
        std::string word;
        while (split >> word) {
            smap[word].emplace(cur_line);
        }
    }
    while (true) {
        std::cout << "Enter a word to query : ";
        std::string word;
        std::cin >> word;
        auto iter = smap.find(word);
        if (iter == smap.end()) {
            std::cout << "Not found" << std::endl;
        } else {
            std::cout << word << " occurs "
                      << iter->second.size()
                      << (iter->second.size() > 1 ? "times" : "time")
                      << std::endl;
            for (auto &ele : iter->second) {
                std::cout << "(line " << ele + 1 << ")"
                          << lines[ele] << std::endl;
            }
        }
        std::cout << "Try again ? y/n  ";
        std::string c;
        std::cin >> c;
        std::cin.sync();
        if (c == "N" || c == "n") break;
    }
    return 0;
}
