/*
 * while循环特别适用于那种条件保持不变、反复执行操作的情况，例如，当未达到文件末尾时不断读取下一个值。
 * for循环则更像是在按步骤迭代，它的索引值在某个范围内依次变化。
 * 根据每种循环的习惯用法各自编写一段程序，然后分别用另一种循环改写。
 * 如果只能使用一种循环，你倾向于使用哪种呢？为什么？
 */

#include <iostream>

int main() {
    int a;
    while (std::cin >> a)
        std::cout << a << std::endl;

    for (; std::cin >> a;)
        std::cout << a << std::endl;

    int sum = 0;
    for (int a = 0; a < 10; ++a)
        sum += a;
    std::cout << sum << std::endl;

    a = 0;
    while (a < 10) {
        sum += a;
        ++a;
    }
    std::cout << sum << std::endl;
    return 0;
}
