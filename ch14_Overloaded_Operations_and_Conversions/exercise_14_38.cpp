/*
 * 编写一个类令其检查某个给定的string对象的长度是否与一个阙值相等。
 * 使用该对象编写程序，统计并报告在输入文件中
 * 长度为1的单词有多少个、长度为2的单词有多少个、....、长度为10的单词又有多少个。
 */


#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>
class func {
    friend std::ostream &operator<<(std::ostream &, const func &);

public:
    func(const int &i) : sz(i) {}
    bool operator()(const std::string &str) const {
        return str.size() == sz;
    }
    func &operator++() {
        ++word_count;
        return *this;
    }

private:
    int sz;
    int word_count = 0;
};


std::ostream &operator<<(std::ostream &os, const func &i) {
    os << "长度为"
       << std::setw(2) << i.sz << "的单词有"
       << i.word_count << std::endl;
    return os;
}

int main(int argc, char const *argv[]) {
    if (argc < 2) exit(1);
    std::ofstream file(argv[1], std::ofstream::out);
    if (!file) exit(1);
    std::ostream_iterator<func> write(file);
    std::string word;
    std::vector<func> cal{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    while (std::cin >> word) {
        std::for_each(cal.begin(), cal.end(), [word](func &i) {if(i(word)) ++i; });
    }
    std::copy(cal.begin(), cal.end(), write);
    file.close();
    return 0;
}
