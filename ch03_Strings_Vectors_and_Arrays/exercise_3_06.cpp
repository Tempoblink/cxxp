/*
 * 编写一段程序，使用范围for语句将字符串内的所有字符用x代替。
 */

#include <iostream>
#include <string>

int main(void) {
    std::string tmp("good day, have fun!");
    for (auto &sign : tmp) {
        sign = 'x';
    }
    std::cout << tmp << std::endl;
    return 0;
}
