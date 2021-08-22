/*
 * 编写一个程序，使其接受本节所示的选项：输出传递给main函数的实参的内容。
 */

#include <iostream>

int main(int argc, char const *argv[]) {
    for (int i = 1; i < argc; ++i)
        std::cout << argv[i] << std::endl;
    return 0;
}
