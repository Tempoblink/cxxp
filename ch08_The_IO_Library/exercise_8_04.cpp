/*
 * 编写函数，以读模式打开一个文件，将其内容都入到一个string的vector中，
 * 将每一行作为一个独立的元素存于vector中。
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void openfile_read(const std::string &file, std::vector<std::string> &line) {
    std::fstream fs(file, std::ios::in);
    if (!fs) exit(1);
    std::string l;
    while (getline(fs, l)) {
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
