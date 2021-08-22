/*
 * 在下面的加法表达式中分别选用了哪个operator+？
 * 列出候选函数、可行函数及为每个可行函数的实参执行的类型转换：
 *
 * struct LongDouble {
 *      LongDouble operator+(const SmallInt&);
 * };
 *
 * LongDouble operator+(LongDouble&, double);
 * SmallInt si;
 * LongDouble ld;
 * ld = si + ld;
 * ld = ld + si;
 */

/*
 * si -> int -> double -> LongDouble   ld -> double -> int -> SmallInt    ===> LongDouble operator+(const SmallInt&) 可行
 * si -> int -> double -> LongDouble   ld -> double      ===> LongDouble operator+(LongDouble&, double) 可行
 * 两个都需要类型转换，存在二义性
 *
 * ld = LongDouble   si = SmallInt    ===>  LongDouble operator+(const SmallInt&) 可行
 * ld = LongDouble   si = SmallInt -> int -> double    ===> LongDouble operator+(LongDouble&, double) 可行
 * 但是 第一个是精确匹配，因此选用第一个。
 */

#include <iostream>

class SmallInt;

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
    LongDouble operator+(const SmallInt &) { std::cout << "operator+(const SmallInt &)" << std::endl; }

private:
    double x;
};
LongDouble operator+(LongDouble &, double) {
    std::cout << "operator+(LongDouble&, double)" << std::endl;
}

class SmallInt {
public:
    SmallInt(const int &v = 0) : val(v) {}
    operator int() const { return val; }

private:
    std::size_t val;
};

int main(int argc, char const *argv[]) {
    SmallInt si;
    LongDouble ld;
    // ld = si + ld;
    ld = ld + si;
    return 0;
}
