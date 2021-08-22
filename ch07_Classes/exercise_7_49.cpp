/*
 * 对于combine函数的三种不同声明，当我们调用i.combine(s)时分别发生什么情况？其中i是一个Sales_data，而s是一个string对象。
 *
 * (a) Sales_data &combine(Sales_data);
 * (b) Sales_data &combine(Sales_data&);
 * (c) Sales_data &combine(const Sales_data&) const;
 */

/*
 * (a) s隐式转换成一个临时的Sales_data对象，然后作为实参传递给成员函数。
 * (b) 错误，不能用临时对象初始化非常量引用。
 * (c) 声明错误，传入const this的函数不能返回非常量的自身引用。 const this 是指向常量对象的常量指针。给常量引用传入临时变量适合的。
 */

#include <iostream>
#include <string>

class Sales_data {
    friend std::ostream &print(std::ostream &os, const Sales_data &s);

public:
    Sales_data() = default;
    Sales_data(std::string s) : bookNo(s) {}
    Sales_data &combine(const Sales_data &) const;

private:
    mutable std::string bookNo;
    mutable unsigned units_sold = 0;
    mutable double revenue = 0.0;
};

Sales_data &Sales_data::combine(const Sales_data &s) const {
    if (bookNo.empty()) {
        bookNo = s.bookNo;
    }
    units_sold += s.units_sold;
    revenue += s.revenue;
    return *const_cast<Sales_data *>(this);
}

std::ostream &print(std::ostream &os, const Sales_data &s) {
    os << s.bookNo << " "
       << s.units_sold << " "
       << s.revenue << std::endl;
    return os;
}

int main(void) {
    Sales_data i;
    std::string s = "C++ primer";
    i.combine(s);
    print(std::cout, i);
    return 0;
}
