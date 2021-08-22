/*
 * 修改统计元音字母的程序，使其能统计以下含有两个字符的字符序列的数量：ff、fl和fi。
 */

#include <iostream>


int main(void) {
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    int ffCnt = 0, flCnt = 0, fiCnt = 0;
    char ch = 0, prech = 0;
    while (std::cin >> std::noskipws >> ch) {
        switch (ch) {
            case 'a':
            case 'A':
                ++aCnt;
                break;
            case 'e':
            case 'E':
                ++eCnt;
                break;
            case 'i':
                if (prech == 'f') ++fiCnt;
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
            case 'f':
                if (prech == 'f') ++ffCnt;
                break;
            case 'l':
                if (prech == 'f') ++flCnt;
                break;
            default:
                break;
        }
        prech = ch;
    }
    std::cout << "a = " << aCnt << std::endl;
    std::cout << "e = " << eCnt << std::endl;
    std::cout << "i = " << iCnt << std::endl;
    std::cout << "o = " << oCnt << std::endl;
    std::cout << "u = " << uCnt << std::endl;
    std::cout << "ff = " << ffCnt << std::endl;
    std::cout << "fl = " << flCnt << std::endl;
    std::cout << "fi = " << fiCnt << std::endl;
    return 0;
}
