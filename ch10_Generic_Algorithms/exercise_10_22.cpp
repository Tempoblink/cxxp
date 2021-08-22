/*
 * 重写统计长度小于等于6的单词数量的程序，使用函数代替lambda。
 */

#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

bool compare_word(const std::string &s, const std::string::size_type size) {
    return s.size() > size;
}

int main(int argc, char const *argv[]) {
    if (argc < 2) exit(1);
    std::fstream file(argv[1], std::fstream::in);
    if (!file) exit(1);
    std::vector<std::string> words;
    std::string word;
    while (file >> word) {
        words.push_back(word);
    }
    auto count = std::count_if(words.begin(), words.end(), std::bind(compare_word, std::placeholders::_1, 6));
    std::cout << "There are " << count << " words longer than 6." << std::endl;
    return 0;
}
