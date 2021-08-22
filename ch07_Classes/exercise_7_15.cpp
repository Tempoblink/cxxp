/*
 * 为你的Person类添加正确的构造函数。
 */

#include <iostream>
#include <string>

struct Person {
    Person() = default;
    Person(std::string add, std::string nam) : address(add), name(nam) {}
    Person(std::istream &);

    std::string Get_address() const { return address; }
    std::string Get_name() const { return name; }
    std::string address;
    std::string name;
};

std::istream &read(std::istream &is, Person &p) {
    is >> p.name >> p.address;
    return is;
}

Person::Person(std::istream &is) {
    read(is, *this);
}

std::ostream &print(std::ostream &os, const Person &p) {
    os << p.name << " "
       << p.address << std::endl;
    return os;
}

int main(void) {
    return 0;
}
