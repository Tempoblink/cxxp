/*
 * 我们之前实现的统计元音字母的程序存在一个问题：如果元音字母以大写形式出现，不会被统计在内。
 * 编写一段程序，既统计元音字母的小写形式，也统计大写形式，也就是说，新程序遇到'a'和'A'都应该递增aCnt的值，以此类推。
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

int main(void) {
    std::vector<int> avec(5, 0);
    char ch;
    while (std::cin >> ch) {
        switch (ch) {
            case 'a':
            case 'A':
                ++avec[a];
                break;
            case 'e':
            case 'E':
                ++avec[e];
                break;
            case 'i':
            case 'I':
                ++avec[i];
                break;
            case 'o':
            case 'O':
                ++avec[o];
                break;
            case 'u':
            case 'U':
                ++avec[u];
                break;
            default:
                break;
        }
    }
    std::cout << "a = " << avec[a] << std::endl;
    std::cout << "e = " << avec[e] << std::endl;
    std::cout << "i = " << avec[i] << std::endl;
    std::cout << "o = " << avec[o] << std::endl;
    std::cout << "u = " << avec[u] << std::endl;
    return 0;
}
