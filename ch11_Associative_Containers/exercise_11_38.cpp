/*
 * 用unordered_map重写单词计数程序（参见11.1节，第375页）
 * 和单词转换程序（参见11.3.6节，第391页）。
 */


#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <sys/_types/_size_t.h>
#include <unordered_map>

std::unordered_map<std::string, std::string> buildMap(std::ifstream &map_file) {
    std::unordered_map<std::string, std::string> trans_map;
    std::string key;
    std::string value;
    //第一个单词存入key， 行剩余部分存入value
    while (map_file >> key && getline(map_file, value)) {
        if (value.size() > 1) {
            //去除开头空格
            trans_map[key] = value.substr(1);
        } else {
            throw std::runtime_error("no rule for " + key);
        }
    }
    return trans_map;
}

const std::string &transform(const std::string &s, const std::unordered_map<std::string, std::string> &m) {
    auto map_it = m.find(s);
    if (map_it != m.cend())
        return map_it->second;
    else
        return s;
}

void word_transform(std::ifstream &map_file, std::ifstream &input) {
    auto trans_map = buildMap(map_file);
    std::string text;
    while (getline(input, text)) {
        std::istringstream stream(text);
        std::string word;
        bool firstword = true;
        while (stream >> word) {
            //单词空格
            if (firstword)
                firstword = false;
            else
                std::cout << " ";
            std::cout << transform(word, trans_map);
        }
        std::cout << std::endl;
    }
}

void word_count(std::ifstream &file) {
    std::unordered_map<std::string, size_t> word_count;
    std::string word;
    while (file >> word) {
        ++word_count[word];
    }
    for (const auto &w : word_count) {
        std::cout << w.first << " occurs "
                  << w.second << ((w.second > 1) ? "times" : "time")
                  << std::endl;
    }
}

int main(int argc, char const *argv[]) {
    if (argc < 4) exit(1);
    std::ifstream map_file(argv[1], std::fstream::in);
    std::ifstream input(argv[2], std::fstream::in);
    std::ifstream file(argv[3], std::fstream::in);
    if (!map_file || !input) exit(1);
    word_transform(map_file, input);
    word_count(file);
    return 0;
}
