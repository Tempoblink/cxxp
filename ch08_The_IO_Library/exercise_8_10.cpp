/*
 * 编写程序，将来自一个文件中的行保存在一个vector<string>中。
 * 然后使用一个istringstream从vector读取数据元素，每次读取一个单词。
 */
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void save_vector(std::ifstream &readfile, std::vector<std::string> &svec) {
    std::string line;
    while (getline(readfile, line)) {
        svec.push_back(line);
    }
}

void print_word(std::istringstream &line) {
    std::string word;
    while (line >> word) {
        std::cout << word << "+ ";
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[]) {
    if (argc < 2) exit(1);
    std::ifstream readfile(argv[1], std::ifstream::in);
    if (!readfile) exit(1);
    std::vector<std::string> svec;
    save_vector(readfile, svec);
    for (const auto &var : svec) {
        std::istringstream line(var);
        print_word(line);
    }
    return 0;
}
