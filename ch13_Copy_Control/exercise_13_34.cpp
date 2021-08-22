/*
 * 编写本节所描述的Message。
 */

#include "include/Folder.h"
#include "include/Messsage.h"
#include <iostream>

int main(int argc, char const *argv[]) {
    Message m1("Hello");
    Message m2("Hey");
    Folder f1("new messages");
    Folder f2("read");
    m1.save(f1);
    m2.save(f1);
    m1.save(f2);
    print(std::cout, m1);
    print(std::cout, m2);
    print(std::cout, f1);
    print(std::cout, f2);
    return 0;
}
