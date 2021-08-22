/*
 * 修改上一题的程序，使用try语句块去捕获异常。catch子句应该为用户输出一条提示信息，询问其是否输出新数并重新执行try语句块的内容。
 */

#include <iostream>
#include <stdexcept>

int main(void) {
    int val1 = 0, val2 = 0;
    while (true) {
        try {
            std::cout << "Enter two numbers: ";
            std::cin >> val1 >> val2;
            if (val2 == 0) throw std::runtime_error("second number can not equal 0");
            std::cout << static_cast<double>(val1) / val2 << std::endl;
            break;
        } catch (std::runtime_error err) {
            std::cout << err.what() << std::endl;
            char c;
            std::cout << "Enter again[y or n]: ";
            std::cin >> c;
            if (!std::cin || c != 'y')
                break;
        }
    }
    return 0;
}
