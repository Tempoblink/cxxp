/*
 * 重写上一题的程序，比较一个list<int>中的元素和一个vector<int>中的元素。
 */

#include <iostream>
#include <list>
#include <vector>

int main(void) {
    std::list<int> li{1, 2, 3, 4, 5};
    std::vector<int> ivec1{1, 2, 3, 4, 5, 6, 7};
    std::vector<int> ivec2(li.cbegin(), li.end());

    std::cout << "ivec1{1,2,3,4,5,6,7} "
              << (ivec1 < ivec2 ? '<' : '>')
              << " li{1,2,3,4,5}"
              << std::endl;
    return 0;
}
