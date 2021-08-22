/*
 * 编写一段程序，使用一系列if语句统计从cin读入的文本中有多少元音字母。
 */

#include <iostream>
#include <vector>

enum alpha {
    a,
    e,
    i,
    o,
    u
};

int main(int argc, char const *argv[]) {
    std::vector<int> avec(5, 0);

    char ch;
    while (std::cin >> ch) {
        if (ch == 'a')
            ++avec[a];
        if (ch == 'e')
            ++avec[e];
        if (ch == 'i')
            ++avec[i];
        if (ch == 'o')
            ++avec[o];
        if (ch == 'u')
            ++avec[u];
    }
    std::cout << "a = " << avec[a] << std::endl;
    std::cout << "e = " << avec[e] << std::endl;
    std::cout << "i = " << avec[i] << std::endl;
    std::cout << "o = " << avec[o] << std::endl;
    std::cout << "u = " << avec[u] << std::endl;
    return 0;
}
