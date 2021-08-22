/*
 * 修改你的程序，使得当第二个数是0时抛出异常。先不要设定catch子句，运行程序并真的为除数输入0，看看会发生什么？
 */

#include <iostream>
#include <stdexcept>

int main(void) {
    int val1 = 0, val2 = 0;
    std::cout << "Enter two numbers: ";
    std::cin >> val1 >> val2;
    if (val2 == 0) throw std::runtime_error("second number can not equal 0");
    std::cout << static_cast<double>(val1) / val2 << std::endl;
    return 0;
}
