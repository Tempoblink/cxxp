/*
 * 编写一个main函数，令其接受两个实参。把实参的内容连接成一个string对象并输出出来。
 */


#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
    std::string s;
    for (int i = 1; i < argc; ++i) {
        s += argv[i];
        s += " ";
    }
    std::cout << "s = " << s << std::endl;
    return 0;
}
