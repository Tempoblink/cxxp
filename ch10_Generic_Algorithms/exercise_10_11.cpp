/*
 * 编写程序，使用stable_sort和isShorter将传递给你的elimDups版本的vector排序。
 * 打印vector的内容，验证你的程序的正确性。
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool isShorter(const std::string &s1, const std::string &s2) {
    return s1.size() < s2.size();
}

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
    std::stable_sort(svec.begin(), svec.end(), isShorter);
    print(std::cout, svec);
    return 0;
}
