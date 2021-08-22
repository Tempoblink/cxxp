/*
 * 描述下面这个函数的行为。如果代码中存在问题，请指出并改正。
 *
 * void print(const int ia[10])
 *   {
 *      for (size_t i = 0; i != 10; ++i)
 *        cout << ia[i] << endl;
 *   }
 */

#include <iostream>

void print(const int (&ia)[10]) {
    std::cout << "ia = " << reinterpret_cast<int_fast64_t>(&ia) << std::endl; 
    for (size_t i = 0; i != 10; ++i) {
        std::cout << ia[i] << " ";
    }
    std::cout << std::endl;
}

int main(void) {
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "a = " << reinterpret_cast<int_fast64_t>(&a) << std::endl;
    print(a);
    return 0;
}
