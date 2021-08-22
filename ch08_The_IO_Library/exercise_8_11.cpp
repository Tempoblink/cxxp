/*
 * 本节的程序在外层while循环中定义了istringstream对象。
 * 如果record对象定义在循环之外，你需要对程序进行怎样的修改？
 * 重写程序，将record的定义移到while循环之外，验证你设想的修改方法是否正确。
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct PersonInfo {
    std::string name;
    std::vector<std::string> phones;
};

void print(std::ostream &os, const PersonInfo &p) {
    os << "info.name\t = " << p.name << std::endl;
    os << "info.phones\t = ";
    for (const auto &phone : p.phones) {
        os << phone;
        if (&phone != &*p.phones.end() - 1)
            os << " , ";
    }
    os << std::endl;
}

int main(int argc, char const *argv[]) {
    if (argc < 2) exit(1);
    std::ifstream readfile(argv[1], std::ifstream::in);
    if (!readfile) exit(1);
    std::string line, word;
    std::vector<PersonInfo> people;
    std::istringstream record;
    while (getline(readfile, line)) {
        PersonInfo info;
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
        record.clear();
    }
    for (const auto &p : people) {
        print(std::cout, p);
    }
    return 0;
}
