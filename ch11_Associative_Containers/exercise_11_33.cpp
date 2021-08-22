/*
 * 实现你自己版本的单词转换程序。
 */

#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

std::map<std::string, std::string> buildMap(std::ifstream &map_file) {
    std::map<std::string, std::string> trans_map;
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

const std::string &transform(const std::string &s, const std::map<std::string, std::string> &m) {
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


int main(int argc, char const *argv[]) {
    if (argc < 3) exit(1);
    std::ifstream map_file(argv[1], std::fstream::in);
    std::ifstream input(argv[2], std::fstream::in);
    if (!map_file || !input) exit(1);
    word_transform(map_file, input);
    return 0;
}
