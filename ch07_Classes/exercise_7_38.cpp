/*
 * 有些情况我们希望提供cin作为接受istream&参数的构造函数的默认实参，请声明这样的构造函数。
 */

#include <iostream>

struct func {
public:
    func(std::istream &is = std::cin) {
        is >> a;
    }
    void print() { std::cout << a << std::endl; }

private:
    int a = 0;
};


int main(void) {
    func f;
    f.print();
    return 0;
}
