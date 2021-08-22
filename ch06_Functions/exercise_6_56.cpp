/*
 * 调用上述vector中的每个元素并输出其结果。
 */

#include <iostream>
#include <vector>

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mutli(int a, int b) {
    return a * b;
}

int dev(int a, int b) {
    return a / b;
}

int main(void) {
    using pf = int (*)(int, int);
    std::vector<pf> pfvec;
    pfvec.push_back(add);
    pfvec.push_back(sub);
    pfvec.push_back(mutli);
    pfvec.push_back(dev);
    std::cout << "1 + 2 = " << pfvec[0](1, 2) << std::endl;
    std::cout << "1 - 2 = " << pfvec[1](1, 2) << std::endl;
    std::cout << "1 * 2 = " << pfvec[2](1, 2) << std::endl;
    std::cout << "1 / 2 = " << pfvec[3](1, 2) << std::endl;
    return 0;
}
