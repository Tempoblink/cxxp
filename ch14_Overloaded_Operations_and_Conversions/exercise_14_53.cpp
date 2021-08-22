/*
 * 假设我们已经定义了如522页所示的SmallInt，判断下面的加法表达式是否合法。
 * 如果合法，使用了哪个加法运算符？如果不合法，应该怎样修改代码才能使其合法。
 * 
 * SmallInt s1;
 * double d = s1 + 3.14;
 */

#include <iostream>

class SmallInt {
    friend SmallInt operator+(const SmallInt &, const SmallInt &);

public:
    SmallInt(const int &v = 0) : val(v) {}
    operator int() const { return val; }

private:
    std::size_t val;
};


SmallInt operator+(const SmallInt &lhs, const SmallInt &rhs) {
    return lhs.val + rhs.val;
}

int main(int argc, char const *argv[]) {
    SmallInt s1;
    double d = static_cast<int>(s1) + 3.14;
    double e = s1 + static_cast<SmallInt>(3.14);
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;
    return 0;
}
