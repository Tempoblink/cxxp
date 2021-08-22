/*
 * 重做上一题，这次使用shared_ptr而不是内置指针。
 */

#include <iostream>
#include <memory>
#include <vector>

std::shared_ptr<std::vector<int>> alloc() {
    return std::make_shared<std::vector<int>>();
}

void write(std::shared_ptr<std::vector<int>> p) {
    int n = 0;
    while (std::cin >> n) {
        p->push_back(n);
    }
}


void read(const std::shared_ptr<std::vector<int>> p) {
    for (auto &mem : *p) {
        std::cout << mem << " ";
    }
    std::cout << std::endl;
}


int main(int argc, char const *argv[]) {
    auto ivec = alloc();
    write(ivec);
    read(ivec);
    return 0;
}
