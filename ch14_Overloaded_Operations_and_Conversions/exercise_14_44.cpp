/*
 * 编写一个简单的桌面计算器使其能处理二元运算。
 */

#include <algorithm>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <vector>

class Expression {
    friend std::ostream &operator<<(std::ostream &, const Expression &);
    friend std::istream &operator>>(std::istream &, Expression &);

public:
    Expression() = default;
    Expression(const int &f, const std::string &si, const int &s)
        : first_int(f), signal(si), second_int(s) { cal_it(); }
    Expression(const Expression &) = default;
    Expression(Expression &&ex) : first_int(std::move(ex.first_int)), signal(std::move(ex.signal)), second_int(std::move(ex.second_int)) {}
    ~Expression() = default;
    void operator()(const Expression &ex) {
        std::cout << ex << std::endl;
    }

private:
    static std::map<std::string, std::function<int(const int, const int)>> fmap;
    int first_int;
    std::string signal;
    int second_int;
    void cal_it();
    int sum = 0;
};

std::map<std::string, std::function<int(const int, const int)>> Expression::fmap = {
        {"+", [](const int a, const int b) { return a + b; }},
        {"-", [](const int a, const int b) { return a - b; }},
        {"*", [](const int a, const int b) { return a * b; }},
        {"/", [](const int a, const int b) -> int {if(!b) std::runtime_error("The divisor not be zero"); return a / b; }}};

std::ostream &operator<<(std::ostream &os, const Expression &ex) {
    os << ex.first_int << " "
       << ex.signal << " "
       << ex.second_int << " "
       << "= " << ex.sum;
    return os;
}
std::istream &operator>>(std::istream &is, Expression &ex) {
    is >> ex.first_int >> ex.signal >> ex.second_int;
    ex.cal_it();
    return is;
}

void Expression::cal_it() {
    auto ret = fmap.find(signal);
    if (ret == fmap.end())
        std::runtime_error("not support");
    sum = ret->second(first_int, second_int);
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        std::cerr << "usage: ex file\n";
        exit(1);
    }
    std::ifstream file(argv[1]);
    if (!file) {
        std::cerr << "can't open the file\n";
        exit(1);
    }
    std::istream_iterator<Expression> read(file), eof;
    std::vector<Expression> evec(read, eof);
    std::for_each(evec.begin(), evec.end(), Expression());
    return 0;
}
