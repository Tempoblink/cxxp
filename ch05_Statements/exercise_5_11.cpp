/*
 * 修改统计元音字母的程序，使其也能统计空格、制表符和换行符的数量。
 */

#include <iostream>


int main(void) {
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    int spaceCnt = 0, tabCnt = 0, newlineCnt = 0;
    char ch = 0;
    while (std::cin >> std::noskipws >> ch) {
        switch (ch) {
            case ' ':
                ++spaceCnt;
                break;
            case '\t':
                ++tabCnt;
                break;
            case '\n':
                ++newlineCnt;
                break;
            case 'a':
            case 'A':
                ++aCnt;
                break;
            case 'e':
            case 'E':
                ++eCnt;
                break;
            case 'i':
            case 'I':
                ++iCnt;
                break;
            case 'o':
            case 'O':
                ++oCnt;
                break;
            case 'u':
            case 'U':
                ++uCnt;
                break;
            default:
                break;
        }
    }
    std::cout << "a = " << aCnt << std::endl;
    std::cout << "e = " << eCnt << std::endl;
    std::cout << "i = " << iCnt << std::endl;
    std::cout << "o = " << oCnt << std::endl;
    std::cout << "u = " << uCnt << std::endl;
    std::cout << "space = " << spaceCnt << std::endl;
    std::cout << "Tab = " << tabCnt << std::endl;
    std::cout << "newline = " << newlineCnt << std::endl;
    return 0;
}
