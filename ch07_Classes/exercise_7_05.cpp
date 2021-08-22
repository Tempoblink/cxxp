/*
 * 在你的Person类中提供一些操作使其能够返回姓名和住址。
 * 这些函数是否应该是const的呢？解释原因。
 */

/*
 * 是const的，因为这样就可以让常量对象调用此成员函数，
 * 否则会因为无法传入顶层const this指针导致无法调用。
 */

#include <iostream>
#include <string>

struct Person {
    std::string Get_address() const { return address; }
    std::string Get_name() const { return name; }
    std::string name;
    std::string address;
};

int main(void) {
    return 0;
}
