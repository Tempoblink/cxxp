/*
 * 扩展你的程序，忽略大小写和标点。
 * 例如，"example.", "example,"和"Example"应该递增相同的计数器。
 */


#include <_ctype.h>
#include <algorithm>
#include <cctype>
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
    while (file >> word) {
        if (word.find(',') != std::string::npos || word.find('.') != std::string::npos)
            word.erase(--word.end());
        if (std::isupper(word[0]))
            word[0] = tolower(word[0]);
        if (exclude.find(word) == exclude.end())
            ++word_count[word];
    }

    for (const auto &word : word_count)
        std::cout << word.first
                  << " occurs "
                  << word.second
                  << ((word.second > 1) ? " times" : " time")
                  << std::endl;
    return 0;
}
