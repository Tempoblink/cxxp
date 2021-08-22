/*
 * 对于7.1.2节（第233页）练习中的代码，添加读取和打印Person对象的操作。
 */

#include <iostream>
#include <string>

struct Person {
    std::string Get_address() const { return address; }
    std::string Get_name() const { return name; }
    std::string address;
    std::string name;
};

std::istream &read(std::istream &is, Person &p) {
    is >> p.name >> p.address;
    return is;
}

std::ostream &print(std::ostream &os, const Person &p) {
    os << p.name << " "
       << p.address << std::endl;
    return os;
}

int main(void) {
    return 0;
}
