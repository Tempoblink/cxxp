/*
 * 标准库定义了名为partition的算法，它接受一个谓词，
 * 对容器内容进行划分，使得谓词为true的值会排在容器的前半部分，
 * 而使谓词为false的值会排在后半部分。
 * 算法返回一个迭代器，指向最后一个谓词为true的元素之后的位置。
 * 编写函数，接受一个string，返回一个bool值，指出string是否有5个或更多字符。
 * 使用此函数划分words。打印出长度大于等于5的元素。
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool half_str(const std::string &s) { return s.size() > 5; }
void print(const std::vector<std::string> &words) {
    for (auto word : words)
        std::cout << word << " ";
    std::cout << std::endl;
}

int main(int argc, char const *argv[]) {
    if (argc < 2)
        exit(1);
    std::fstream file(argv[1], std::fstream::in);
    if (!file)
        exit(1);
    std::string word;
    std::vector<std::string> words;
    while (file >> word)
        words.push_back(word);
    print(words);
    std::partition(words.begin(), words.end(), half_str);
    print(words);

    return 0;
}
