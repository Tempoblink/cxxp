/*
 * 再一次改写程序，这次使用auto关键字。
 */


#include <iostream>

const size_t ZERO = 0;

int main(void) {
    int ia[3][4] = {
            {0, 1, 2, 3},
            {4, 5, 6, 7},
            {8, 9, 10, 11}};

    constexpr size_t icol = sizeof(ia[0]) / sizeof(ia[0][0]);
    constexpr size_t irow = sizeof(ia) / sizeof(ia[0]);

    //1
    for (const auto &row : ia) {
      for (const auto &col : row) {
        std::cout << col << "\t";
      }
      std::cout << std::endl;
    }

    //2
    
    for (auto i = ZERO; i < irow; ++i) {
        for (auto j = ZERO; j < icol; ++j) {
            std::cout << ia[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    //3
    for (const auto *p = ia; p != ia + irow; ++p) {
      for (const auto *q = *p; q != *p + icol; ++q) {
        std::cout << *q << "\t"; 
      }
      std::cout << std::endl;
    }
    return 0;
}
