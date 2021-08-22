/*
 * 理解拷贝控制成员和构造函数的一个好方法是定义一个简单的类，
 * 为该类定义这些成员，每个成员都打印出自己的名字:
 * struct X {
 *    X() {std::cout << "X()" << std::endl;}
 *    X(const X&) {std::cout << "X(const X&)" << std::endl;
 * };
 * 给X添加拷贝赋值运算符和析构函数，并编写一个程序以不同方式使用X的对象；
 * 将它们作为非引用和引用参数传递；动态分配它们；将它们放于容器中；诸如此类。
 * 观察程序的输出，直到你确认理解了什么时候会使用拷贝控制成员，以及为什么会使用它们。
 * 当你观察程序输出时，记住编译器可以略过对拷贝构造函数的调用。
 */

#include <iostream>

class X {
public:
    X() { std::cout << "X()" << std::endl; }
    X(const X &x) : num(x.num) { std::cout << "X(const X&)" << std::endl; }
    X &operator=(const X &rhs) {
        num = rhs.num;
        std::cout << "X& operator=(const X &)" << std::endl;
        return *this;
    }
    ~X() { std::cout << "~X()" << std::endl; }

private:
    int num = 0;
};

void test1(X) { std::cout << "test1(X)" << std::endl; };
void test2(X &) { std::cout << "test2(X &)" << std::endl; };

int main(int argc, char const *argv[]) {
    X x1;
    X x2(x1);
    x1 = x2;
    std::cout << "-----Start-----" << std::endl;
    test1(x1);
    std::cout << "------END------" << std::endl;
    std::cout << "-----Start-----" << std::endl;
    test2(x1);
    std::cout << "------END------" << std::endl;
    return 0;
}
