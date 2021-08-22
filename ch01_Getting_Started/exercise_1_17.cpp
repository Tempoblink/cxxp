/*
 * 如果输入的所有值都是相等的，本节的程序会输出什么？如果没有重复值，输出又会是怎样的？
 */

/*
 * 1 1 1 1 1 1
 * 1 occurs 6 times
 */

/*
 * 1 2 3 4 5
 * 1 occurs 1 times 
 * 2 occurs 1 times
 * 3 occurs 1 times
 * 4 occurs 1 times
 * 5 occurs 1 times
 */

#include <iostream>

int main(void) {
    int currVal = 0, val = 0;
    if (std::cin >> currVal) {
        int cnt = 1;
        while (std::cin >> val) {
            if (val == currVal) {
                ++cnt;
            } else {
                std::cout << currVal << " occurs "
                          << cnt << " tiems" << std::endl;
                currVal = val;
                cnt = 1;
            }
        }
        std::cout << currVal << " occurs "
                  << cnt << " times" << std::endl;
    }
    return 0;
}
