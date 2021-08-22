/*
 * 重写biggies，用partition代替find_if。
 * 我们在10.3.1节练习10.13（第345页）中介绍了partition算法。
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

void elimDups(std::vector<std::string> &);
std::string make_plural(std::vector<std::string>::size_type, const std::string &, const std::string &);

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz) {
    elimDups(words);

    std::stable_sort(words.begin(), words.end(), [](const std::string &a, const std::string &b) { return a.size() < b.size(); });

    // auto wc = std::find_if(words.begin(), words.end(), [sz](const std::string &a) { return a.size() >= sz; });
    auto wc = std::partition(words.begin(), words.end(), [sz](const std::string &a) { return a.size() < sz; });
    auto count = words.end() - wc;
    std::cout << count << " "
              << make_plural(count, "word", "s") << " of length "
              << sz << " or longer" << std::endl;

    std::for_each(wc, words.end(), [](const std::string &s) { std::cout << s << " "; });
    std::cout << std::endl;
}

void elimDups(std::vector<std::string> &words) {
    std::sort(words.begin(), words.end());

    auto end_unique = std::unique(words.begin(), words.end());

    words.erase(end_unique, words.end());
}
std::string make_plural(std::vector<std::string>::size_type count, const std::string &word, const std::string &s) {
    return count > 1 ? word + s : word;
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
    biggies(words, 5);
    return 0;
}
