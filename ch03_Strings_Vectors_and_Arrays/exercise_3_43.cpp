/*
 * 编写3个不同版本的程序，令其均能输出ia的元素，
 * 版本1使用范围for语句管理迭代过程；
 * 版本2和版本3都使用普通的for语句，其中版本2要求用下标运算符，版本3要求用指针。
 * 此外，在所有3个版本的程序中都要直接写出数据类型，而不能使用类型别名、auto关键字或decltype关键字。
 */

#include <iostream>

int main(void) {
    int ia[3][4] = {
            {0, 1, 2, 3},
            {4, 5, 6, 7},
            {8, 9, 10, 11}};

    //1
    constexpr size_t icol = sizeof(ia[0]) / sizeof(ia[0][0]);
    for (int(&row)[icol] : ia) {
        for (const int &col : row) {
            std::cout << col << "\t";  
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //2
    constexpr size_t irow = sizeof(ia) / sizeof(ia[0]);
    for (size_t i = 0; i < irow; ++i) {
        for (size_t j = 0; j < icol; ++j) {
            std::cout << ia[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //3
    for (int (*i)[icol] = ia; i != ia + irow; ++i) {
      for (int *j = *i ;j != *i + icol; ++j) {
        std::cout << *j << "\t";
      }
      std::cout << std::endl;
        
    }
    return 0;
}
