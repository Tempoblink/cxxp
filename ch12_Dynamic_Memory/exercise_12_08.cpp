/*
 * 下面的函数是否有错误？如果有，解释错误原因。
 * 
 * bool b() {
 *    int *p = new int;
 *    ...
 *    return p;
 * }
 */

/*
 * 无语法错误，但是存在逻辑错误。
 * 且内置型指针p未释放。
 */

#include <iostream>

bool b() {
    int *p = new int;
    // *p = 10;
    return p;
}


int main(int argc, char const *argv[]) {
    std::cout << "result = " << b() << std::endl;
    return 0;
}
