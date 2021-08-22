/*
 * 如果你试图拷贝或赋值unique_ptr，编译器并不总是能给出易于理解的错误信息。
 * 编写包含这种错误的程序，观察编译器如何诊断这种错误。
 */

#include <memory>

int main(int argc, char const *argv[]) {
    std::unique_ptr<int> p(new int(42));
    std::unique_ptr<int> q(p);
    return 0;
}
