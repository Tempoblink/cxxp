/*
 * 重写11.1节练习（第376页）的单词计数程序，
 * 使用insert代替下标操作。你认为哪个程序更容易编写和阅读？解释原因。
 */


#include <cstddef>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>

int main(int argc, char const *argv[]) {
    if (argc < 2) exit(1);
    std::fstream file(argv[1], std::fstream::in);
    if (!file) exit(1);

    std::map<std::string, std::size_t> word_count;
    std::set<std::string> exclude = {
            "The", "But", "And", "Or", "An", "A",
            "the", "but", "and", "or", "an", "a"};
    std::string word;
    while (file >> word)
        if (exclude.find(word) == exclude.end()) {
            auto ret = word_count.insert({word, 1});
            if (!ret.second)
                ++ret.first->second;
        }

    for (const auto &word : word_count)
        std::cout << word.first
                  << " occurs "
                  << word.second
                  << ((word.second > 1) ? "times" : "time")
                  << std::endl;
    return 0;
}
