/*
 * 重做上一题，但读取string序列存入list中。
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <string>

int main(int argc, char const *argv[]) {
    if (argc < 2)
        exit(1);
    std::fstream file(argv[1], std::fstream::out | std::fstream::app);
    if (!file)
        exit(1);
    std::string word;
    while (std::cin >> word) {
        file << word << "\n";
    }
    file.close();
    file.open(argv[1], std::fstream::in);
    std::list<std::string> slist;
    while (file >> word) {
        slist.push_back(word);
    }
    file.close();
    std::cout << "Hello : "
              << std::count(slist.begin(), slist.end(), "Hello")
              << std::endl;
    return 0;
}
