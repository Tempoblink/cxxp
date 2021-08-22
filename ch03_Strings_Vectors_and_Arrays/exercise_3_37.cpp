/*
 * 下面的程序适合含义，程序的输出结果是什么？
 *
 * const char ca[] = {'h', 'e', 'l', 'l', 'o'};
 * const char *cp = ca;
 * while (*cp) {
 *    cout << *cp << endl;
 *    ++cp;
 * }
 */

/*
 * 输出ca数组中的内容，但未以空字符结尾，运行结果未定义。
 */

#include <iostream>

int main(void) {
    const char ca[] = {'h', 'e', 'l', 'l', 'o'};
    const char *cp = ca;
    while (*cp) {
        std::cout << *cp << std::endl;
        ++cp;
    }

    return 0;
}
