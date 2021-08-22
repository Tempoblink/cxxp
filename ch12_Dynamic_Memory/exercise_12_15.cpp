/*
 * 重写第一题的程序，用lambda（参见10.3.2节，第346页）代替end_connection函数。
 */


#include <iostream>
#include <iterator>
#include <memory>
#include <string>

struct destination {
    std::string addr_ip;
};

struct connection {
    std::string *addr_ip;
};

connection connect(destination *dest) {
    std::cout << "connect:\t ";
    connection c;
    c.addr_ip = new std::string(dest->addr_ip);
    std::cout << *c.addr_ip << std::endl;
    return c;
}

void disconnect(connection &c) {
    std::cout << "disconnect:\t " << *c.addr_ip << std::endl;
    delete c.addr_ip;
}

void f(destination &dest) {
    connection c = connect(&dest);
    std::shared_ptr<connection> p(&c, [](connection *c){disconnect(*c);});
}

int main(int argc, char const *argv[]) {
    destination p;
    p.addr_ip = "192.168.1.1";
    f(p);
    return 0;
}
