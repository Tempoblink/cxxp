/*
 * 在上一题的程序中，至少有三种创建pair的方法。
 * 编写此程序的三个版本，分别采用不同的方法创建pair。
 * 解释你认为哪种形式最易于编写和理解，为什么？
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
        // s1.push_back({word, num});
        // s1.push_back(std::pair<std::string, int>(word, num));
        // s1.push_back(std::make_pair(word, num));
        s1.emplace_back(word, num);
    }
    for (const auto &i : s1) {
        std::cout << i.first << " " << i.second << std::endl;
    }

    return 0;
}
