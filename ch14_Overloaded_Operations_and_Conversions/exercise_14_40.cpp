/*
 * 重新编写10.3.2节（第349页）的biggiest函数，
 * 使用函数对象类替换其中的lambda表达式。
 */

#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

class CompareString {
public:
    bool operator()(const std::string &a, const std::string &b) {
        return a.size() < b.size();
    }
};

class BiggerSize {
public:
    BiggerSize(const std::size_t i) : sz(i) {}
    bool operator()(const std::string &a) {
        return a.size() >= sz;
    }

private:
    std::size_t sz;
};

class PrintString {
public:
    PrintString(std::ostream &a) : os(a) {}
    void operator()(const std::string &str) const {
        os << str << ' ';
    }

private:
    std::ostream &os;
};

void elimDups(std::vector<std::string> &);
std::string make_plural(std::vector<std::string>::size_type, const std::string &, const std::string &);

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz) {
    elimDups(words);

    std::stable_sort(words.begin(), words.end(), CompareString());

    auto wc = std::find_if(words.begin(), words.end(), BiggerSize(sz));
    auto count = words.end() - wc;
    std::cout << count << " "
              << make_plural(count, "word", "s") << " of length "
              << sz << " or longer" << std::endl;

    std::for_each(wc, words.end(), PrintString(std::cout));
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
