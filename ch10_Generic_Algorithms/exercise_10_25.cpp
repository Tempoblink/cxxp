/*
 * 在10.3.2节（第349页）的练习中，编写了一个使用partition的biggies版本。
 * 使用check_size和bind重写此函数。
 */

#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

void elimDups(std::vector<std::string> &);
std::string make_plural(std::vector<std::string>::size_type, const std::string &, const std::string &);
bool check_size(const std::string &s, const std::string::size_type sz);

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz) {
    elimDups(words);

    std::stable_sort(words.begin(), words.end(), [](const std::string &a, const std::string &b) { return a.size() < b.size(); });

    // auto wc = std::find_if(words.begin(), words.end(), [sz](const std::string &a) { return a.size() >= sz; });
    // auto wc = std::partition(words.begin(), words.end(), [sz](const std::string &a) { return a.size() < sz; });
    auto wc = std::find_if(words.begin(), words.end(), std::bind(check_size, std::placeholders::_1, sz));
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

bool check_size(const std::string &s, const std::string::size_type sz) {
    return s.size() >= sz;
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
