/*
 * 重写上面的程序，将每个单词作为一个独立的元素进行存储。
 */


#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void openfile_read(const std::string &file, std::vector<std::string> &line) {
    std::fstream fs(file, std::ios::in);
    if (!fs) exit(1);
    std::string l;
    //getline(fs,l);
    while (fs >> l) {
        line.push_back(l);
    }
    fs.close();
}

int main(int argc, char const *argv[]) {
    if (argc < 2) exit(1);
    std::vector<std::string> line;
    openfile_read(argv[1], line);
    for (const auto &l : line) {
      std::cout << l << std::endl;
    }
    return 0;
}
