/*
 * 使用前一个练习定义的类读取标准输入，
 * 将每一行保存为vector的一个元素。
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class PrintString {
public:
    PrintString(std::istream &input = std::cin) : is(input) {}
    std::string operator()() {
        std::getline(is, str);
        return str;
    }

private:
    std::istream &is;
    std::string str;
};

int main(int argc, char const *argv[]) {
    if (argc < 2) exit(1);
    std::ifstream file(argv[1], std::ifstream::in);
    if (!file) exit(1);
    PrintString getLine(file);
    std::string line;
    std::vector<std::string> svec;
    while (!(line = getLine()).empty()) {
        svec.push_back(line);
    }
    std::for_each(svec.begin(), svec.end(), [](const std::string &s) { std::cout << s << std::endl; });
    return 0;
}
