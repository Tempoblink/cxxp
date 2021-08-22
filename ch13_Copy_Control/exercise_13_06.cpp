/*
 * 拷贝赋值运算符是什么？什么时候使用它？
 * 合成拷贝赋值运算符完成什么工作？
 * 什么时候会生成合成拷贝赋值运算符？
 */

/*
 * 拷贝赋值运算符接受一个本类型对象的赋值运算符版本。
 * 通常，拷贝赋值运算符的参数是一个const的引用，并返回指向本对象的引用。
 * 如果类未显式定义拷贝赋值运算符，编译器会为它合成一个。
 *
 * 当发生赋值操作的时候会使用。
 *
 * 将右侧运算对象的每个非static成员赋予左侧运算对象的对应成员。
 *
 * 如果一个类未定义自己的拷贝赋值运算符，编译器会为它生成一个。
 */

#include <string>
class Sales_data {
public:
    Sales_data &operator=(const Sales_data &);

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data &Sales_data::operator=(const Sales_data &rhs) {
    bookNo = rhs.bookNo;
    units_sold = rhs.units_sold;
    revenue = rhs.revenue;
    return *this;
}

int main(int argc, char const *argv[]) {
    return 0;
}
