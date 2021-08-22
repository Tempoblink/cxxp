/*
 * 编写函数，返回一个动态分配的int的vector。
 * 将此vector传递给另一个函数，
 * 这个函数读取标准输入，将读入的值保存在vector元素中。
 * 再将vector传递给另一个函数，打印读入的值。记得在恰当的时刻delete vector。
 */

#include <iostream>
#include <memory>
#include <vector>

std::vector<int> *alloc() {
    return new std::vector<int>();
}

void write(std::vector<int> *p) {
    int n = 0;
    while (std::cin >> n) {
        p->push_back(n);
    }
}

void read(const std::vector<int> *p) {
    for (auto &mem : *p) {
        std::cout << mem << " ";
    }
    std::cout << std::endl;
}


int main(int argc, char const *argv[]) {
    auto ivec = alloc();
    write(ivec);
    read(ivec);
    delete ivec;
    return 0;
}
