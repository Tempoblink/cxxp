/*
 * 实现你自己的elimDups。测试你的程序，
 * 分别在读取输入后、调用unique后以及调用erase后打印vector的内容。
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

void print(std::ostream &os, const std::vector<std::string> &s) {
    for (auto &i : s)
        os << i << " ";
    os << std::endl;
}

void elimDups(std::vector<std::string> &words) {
    std::sort(words.begin(), words.end());

    auto end_unique = std::unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

int main(int argc, char const *argv[]) {
    if (argc < 2)
        exit(1);
    std::fstream file(argv[1], std::fstream::in);
    if (!file)
        exit(1);
    std::vector<std::string> svec;
    std::string word;
    while (file >> word) {
        svec.push_back(word);
    }
    file.close();
    print(std::cout, svec);
    elimDups(svec);
    print(std::cout, svec);
    return 0;
}
