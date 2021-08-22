/*
 * 改写上一个练习中的程序，使用类型别名来代替循环控制变量的类型。
 */


#include <iostream>

int main(void) {
    int ia[3][4] = {
            {0, 1, 2, 3},
            {4, 5, 6, 7},
            {8, 9, 10, 11}};
    constexpr size_t icol = sizeof(ia[0]) / sizeof(ia[0][0]);
    constexpr size_t irow = sizeof(ia) / sizeof(ia[0]);

    //1
    using row1 = const int(&)[icol];
    using col1 = const int&;
    for (row1 row : ia) {
        for (col1 col : row) {
            std::cout << col << "\t";
        }
        std::cout << std::endl;
    }

    //2
    using row2 = size_t;
    using col2 = size_t;
    for (row2 row = 0; row < irow; ++row) {
      for (col2 col = 0; col < icol; ++col) {
          std::cout << ia[row][col] << "\t";
      }
      std::cout << std::endl;
    }

    //3
    using row3 = const int (*)[icol];
    using col3 = const int *;
    for (row3 row = ia; row < ia + irow; row++) {
      for (col3 col = *row; col < *row + icol; col++) {
        std::cout << *col << "\t";
      }
      std::cout << std::endl;
    }
    return 0;
}
