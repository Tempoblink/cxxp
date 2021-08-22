/*
 * 下面的范围for语句合法吗？如果合法，c的类型是什么？
 *
 * const string s = "Keep out!";
 * for (auto &c : s) { ... }
 */

/*
 * 合法，c的类型为 const char &，但不能修改其值。
 */

#include <iostream>
#include <string>

int main(void) {
    const std::string s = "Keep out!";
    for (auto &c : s) {
        std::cout << c;
        // c = 'x';
    }
    std::cout << std::endl;
    return 0;
}
