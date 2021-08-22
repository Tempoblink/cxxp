/*
 * 定义一个map，关键字是家庭的姓，值是一个vector，保存家中孩子们的名。
 * 编写代码，实现添加新的家庭以及向已有家庭中添加新的孩子。
 */

#include <fstream>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <string>
#include <vector>

class Name {
    friend std::istream &operator>>(std::istream &, Name &);
    friend std::ostream &operator<<(std::ostream &, const Name &);

public:
    Name() = default;
    Name(const std::string &lastname, const std::string &firstname) : _lastname(lastname), _firstname(firstname) {}
    Name(std::istream &is) { is >> *this; }

    std::string family() const { return _lastname; }
    std::string given() const { return _firstname; }

private:
    std::string _lastname;
    std::string _firstname;
};

std::istream &operator>>(std::istream &is, Name &name) {
    is >> name._lastname >> name._firstname;
    if (!is) name = Name();
    return is;
}

std::ostream &operator<<(std::ostream &os, const Name &name) {
    os << name._lastname << name._firstname;
    return os;
}


int main(int argc, char const *argv[]) {
    if (argc < 2) exit(1);
    std::fstream file(argv[1], std::fstream::in);
    if (!file) exit(1);
    std::map<std::string, std::vector<std::string>> family;
    std::istream_iterator<Name> read_in(file), read_end;
    while (read_in != read_end) {
        family[(*read_in).family()].push_back((*read_in).given());
        ++read_in;
    }
    file.close();
    for (const auto &one : family) {
        std::cout << "Family\t: " << one.first << std::endl;
        std::cout << "Child\t: ";
        for (const auto &child : one.second) {
            std::cout << child << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
