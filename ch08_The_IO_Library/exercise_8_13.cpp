/*
 * 重写本节的电话号码程序，从一个命名文件而非cin读取数据。
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
