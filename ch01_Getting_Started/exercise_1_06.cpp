/*
 * 解释下面程序片段是否合法。
 * std::cout << "The sum of " <<v1;
 *           << " and " << v2;
 *           << " is " << v1 + v2 << std::endl;
 */

/*
 * 不合法，分号代表一句结束。应删除分号。
 */

#include <iostream>

int main(void) {
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The sum of " << v1 << " and " << v2
              << " is " << v1 + v2 << std::endl;
    return 0;
}
