/*
 * 修改上一题的程序令其报告长度
 * 在1至9之间的单词有多少个、长度在10以上的单词又有多少个？
 */

#include <algorithm>
#include <cstdint>
#include <fstream>
#include <i386/limits.h>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>

class func {
    friend std::ostream &operator<<(std::ostream &, const func &);

public:
    func(const std::size_t &i, const std::size_t &j) : sz_min(i), sz_max(j) {}
    bool operator()(const std::string &str) const {
        return (str.size() >= sz_min) && (str.size() <= sz_max);
    }
    func &operator++() {
        ++word_count;
        return *this;
    }

private:
    std::size_t sz_min;
    std::size_t sz_max;
    unsigned word_count = 0;
};


std::ostream &operator<<(std::ostream &os, const func &i) {
    os << "长度"
       << std::setw(3)<< i.sz_min
       << " - "
       << std::setw(3) << ((i.sz_max != SIZE_T_MAX) ? std::to_string(i.sz_max) : "Max")
       << "的单词有"
       << i.word_count << std::endl;
    return os;
}

int main(int argc, char const *argv[]) {
    if (argc < 2) exit(1);
    std::ofstream file(argv[1], std::ofstream::out);
    if (!file) exit(1);
    std::ostream_iterator<func> write(file);
    std::string word;
    std::vector<func> cal{{1, 9}, {10, SIZE_T_MAX}};
    while (std::cin >> word) {
        std::for_each(cal.begin(), cal.end(), [word](func &i) {if(i(word)) ++i; });
    }
    std::copy(cal.begin(), cal.end(), write);
    file.close();
    return 0;
}
