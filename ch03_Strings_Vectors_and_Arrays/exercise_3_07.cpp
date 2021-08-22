/*
 * 就上一题完成的程序而言，如果将循环控制变量的类型设为char将发声明什么？
 * 先估计一下结果，然后实际编程进行验证。
 */

/*
 * 原值输出，并未改变未x。
 */


#include <iostream>
#include <string>

int main(void) {
    std::string tmp("good day, have fun!");
    for (char var : tmp) {
        var = 'x';
    }
    std::cout << tmp << std::endl;
    return 0;
}
