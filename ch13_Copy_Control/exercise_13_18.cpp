/*
 * 定义一个Employee类，它包含雇员的姓名和唯一的雇员编号。
 * 为这个类定义默认构造函数，以及接受一个表示雇员姓名的string的构造函数。
 * 每个构造函数应该通过递增一个static数据成员来生成一个唯一的证号。
 */

#include <iostream>
#include <string>

class Employee;
void print(std::ostream &, const Employee &);

class Employee {
    friend void print(std::ostream &, const Employee &);

public:
    Employee() : _id(get_id) { make_id(); }
    Employee(const std::string &name) : Employee() { _name = name; }
    Employee(const Employee &) = delete;
    Employee &operator=(const Employee &) = delete;
    ~Employee() {}

private:
    void make_id() { ++get_id; }
    static int get_id;
    std::string _name;
    int _id;
};

int Employee::get_id = 0;
void print(std::ostream &os, const Employee &em) {
    os << "----Personal info----" << std::endl
       << "Name:\t" << em._name << std::endl
       << "ID:\t" << em._id << std::endl;
}

int main(int argc, char const *argv[]) {
    std::string name = "Lippman";
    Employee first(name);

    print(std::cout, first);
    return 0;
}
