/*
 * 本节的程序使用了前置版本的递增运算符和递减运算符，解释为什么要用前置版本而不用后置版本。
 * 要想使用后置版本的递增递减运算符需要做哪些改动？使用后置版本重写本节的程序。
 */

/*
 * 前置版本的内存开支比后置小。
 * 因为后置版本需要保留一份原始对象的副本将其作为运算结果，而前置不用。见p132。
 */

#include <iostream>
#include <vector>

int main(void) {
    std::vector<int> ivec(10);
    std::vector<int>::size_type cnt = ivec.size();
    for (std::vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--) {
        ivec[ix] = cnt;
    }
    for (const auto &i : ivec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
