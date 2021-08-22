/*
 * 扩展你在11.2.1节练习（第378页）中编写的孩子姓到名的map，
 * 添加一个pair的vector，保存孩子的名和生日
 */


#include <fstream>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <string>
#include <utility>
#include <vector>

class Name {
    friend std::istream &operator>>(std::istream &, Name &);
    friend std::ostream &operator<<(std::ostream &, const Name &);

public:
    Name() = default;
    Name(const std::string &lastname, const std::string &firstname, const std::string &birthday)
        : _lastname(lastname), _firstname(firstname), _birthday(birthday) {}
    Name(std::istream &is) { is >> *this; }

    std::string family() const { return _lastname; }
    std::string given() const { return _firstname; }
    std::string birth() const { return _birthday; }

private:
    std::string _lastname;
    std::string _firstname;
    std::string _birthday;
};

std::istream &operator>>(std::istream &is, Name &name) {
    is >> name._lastname >> name._firstname >> name._birthday;
    if (!is) name = Name();
    return is;
}

std::ostream &operator<<(std::ostream &os, const Name &name) {
    os << name._lastname << name._firstname << name._birthday;
    return os;
}


int main(int argc, char const *argv[]) {
    if (argc < 2) exit(1);
    std::fstream file(argv[1], std::fstream::in);
    if (!file) exit(1);
    std::map<std::string, std::vector<std::pair<std::string, std::string>>> family;
    std::istream_iterator<Name> read_in(file), read_end;
    while (read_in != read_end) {
        family[(*read_in).family()].emplace_back((*read_in).given(), (*read_in).birth());
        ++read_in;
    }
    file.close();
    for (const auto &one : family) {
        std::cout << "Family\t: " << one.first << std::endl;
        std::cout << "Child: " << std::endl;
        for (const auto &child : one.second) {
            std::cout << "\t" << child.first << "\t";
            std::cout << child.second << std::endl;
        }
    }
    return 0;
}
