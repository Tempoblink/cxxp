/*
 * 定义一个函数对象类，令其执行if-then-else的操作；
 * 该类的调用运算符接受三个形参：它首先检查第一个形参，
 * 如果成功返回第二个形参的值；如果不成功返回第三个形参的值。
 */

#include <iostream>

class func {
public:
    int operator()(const int &a, const int &b, const int &c) const {
        return a ? b : c;
    }
};


int main(int argc, char const *argv[]) {
    func test;
    std::cout << test(0, 1, 2) << std::endl;
    return 0;
}
