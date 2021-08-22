/*
 * 根据4.12节中的表（第147页）说明下面这条表达式的含义：
 *
 * someValue ? ++x, ++y : --x, --y
 */

/*
 * ,是左结合。：是右结合。
 * (someValue ? ++x, ++y : --x), --y;  --y 无论如何都会执行。
 */

#include <iostream>

int main(void) {
    int x = 0, y = 0;
    1 ? ++x, ++y : --x, --y;
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    return 0;
}
