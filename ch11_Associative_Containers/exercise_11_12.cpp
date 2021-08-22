/*
 * 编写程序，读入string和int的序列，
 * 将每个string和int存入一个pair中，pair保存在一个vector中。
 */

#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main(int argc, char const *argv[]) {
    if (argc < 2) exit(1);
    std::fstream file(argv[1], std::fstream::in);
    if (!file) exit(1);
    std::vector<std::pair<std::string, int>> s1;
    std::string word;
    int num = 0;
    while (file >> word >> num) {
        s1.push_back(std::make_pair(word, num));
    }
    for (const auto &i : s1) {
        std::cout << i.first << " " << i.second << std::endl;
    }

    return 0;
}
