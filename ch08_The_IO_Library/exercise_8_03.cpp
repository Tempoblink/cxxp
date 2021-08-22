/*
 * 什么情况下，下面的while循环会终止？
 * while (cin >> i) ...
 */

/*
 * 当流崩溃(badbit)、IO操作失败(failbit)、流到达了文件尾时(eofbit)，检测流状态的条件会失败，while循环终止。
 */

#include <iostream>

int main(void) {
    int i = 0;
    while (std::cin >> i) {
        std::cout << "badbit\t = " << std::istream::badbit << std::endl;
        std::cout << "failbit\t = " << std::istream::failbit << std::endl;
        std::cout << "eofbit\t = " << std::istream::eofbit << std::endl;
    }
    std::cout << "badbit\t = " << std::istream::badbit << std::endl;
    std::cout << "failbit\t = " << std::istream::failbit << std::endl;
    std::cout << "eofbit\t = " << std::istream::eofbit << std::endl;
    return 0;
}
