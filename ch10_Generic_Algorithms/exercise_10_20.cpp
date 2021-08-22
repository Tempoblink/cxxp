/*
 * 标准库定义了一个名为count_if的算法。
 * 类似find_if，此函数接受一对迭代器，表示一个输入范围，还接受一个谓词，会对输入范围中每个元素执行。
 * count_if返回一个计数值，表示谓词有多少次为真。使用count_if重写我们程序中统计有多少单词长度超过6的部分。
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
    if (argc < 2) exit(1);
    std::fstream file(argv[1], std::fstream::in);
    if (!file) exit(1);
    std::vector<std::string> words;
    std::string word;
    while (file >> word) {
        words.push_back(word);
    }
    auto count = std::count_if(words.begin(), words.end(), [](const std::string &s) { return s.size() > 6; });
    std::cout << "There are " << count << " words longer than 6." << std::endl;
    return 0;
}
