/*
 * 说明下面这个循环的含义，它对assert的使用合理吗？
 *
 * string s;
 * while (cin >> s && s != sought) {} // 空函数体
 * assert(cin);
 */

/*
 * 不管怎么样，程序都会输出信息，并终止执行，所以assert使用的不合理。当调试器关闭后，assert什么也不做。
 */
#include <iostream>
#include <string>
#include <cassert>

int main(void) {
    std::string sought("Hello");
    std::string s;
    while (std::cin >> s && s != sought)
        ;
    assert(std::cin);
    return 0;
}
