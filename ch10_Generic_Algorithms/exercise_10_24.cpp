/*
 * 给定一个string，使用bind和check_size在一个int的vector中查找第一个大于string长度的值。
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

bool check_size(const std::string &s, std::string::size_type sz) {
    return s.size() < sz;
}

int main(int argc, char const *argv[]) {
    std::vector<int> ivec{2, 3, 4, 1, 5, 9, 7, 6, 8};
    std::string word("Hello");
    auto wc = std::find_if(ivec.begin(), ivec.end(), std::bind(check_size, word, std::placeholders::_1));
    if (wc != ivec.end()) {
        std::cout << *wc << std::endl;
    } else {
        std::cout << "Not found." << std::endl;
    }
    return 0;
}
