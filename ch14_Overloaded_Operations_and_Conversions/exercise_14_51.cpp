/*
 * 在调用calc的过程中，可能用到哪些类型转换序列呢？
 * 说明最佳可行函数是如何被选出来的。
 *
 * void calc(int);
 * void calc(LongDouble);
 * double dval;
 * calc(dval);    //哪个calc?
 */

#include <iostream>

struct LongDouble {
    LongDouble(const double &i = 0.0) : x(i) {}
    operator double() {
        std::cout << "double()" << std::endl;
        return x;
    }
    operator float() {
        std::cout << "float()" << std::endl;
        return x;
    }

private:
    double x;
};

void calc(int) {
    std::cout << "calc(int)" << std::endl;
}

void calc(LongDouble) {
    std::cout << "calc(LongDouble)" << std::endl;
}

int main(int argc, char const *argv[]) {
    double dval;
    calc(dval);
    return 0;
}
