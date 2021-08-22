/*
 * 在下述语句中，当赋值完成后i和d的值分别是多少？
 *
 * int i; double d;
 * (a) d = i = 3.5;         (b) i = d = 3.5;
 */


/*
 * (a) i = 3, d = 3;
 * (b) i = 3, d = 3.5;
 */


#include <iostream>

int main(void) {
    int i;
    double d;

    //a
    std::cout << "(a) d = i = 3.5" << std::endl;
    d = i = 3.5;
    std::cout << "i = " << i << ", d = " << d << std::endl;


    //b
    std::cout << "(b) i = d = 3.5" << std::endl;
    i = d = 3.5;
    std::cout << "i = " << i << ", d = " << d << std::endl;
    return 0;
}
