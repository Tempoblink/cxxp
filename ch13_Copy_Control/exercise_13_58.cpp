/*
 * 编写新版本的Foo类，其sorted函数中有打印语句，
 * 测试这个类，来验证你对前两题的答案是否正确。
 */

#include <initializer_list>
#include <iostream>
#include <type_traits>
#include <vector>

class Foo {
public:
    explicit Foo(std::initializer_list<int> li);
    Foo sorted() &&;
    Foo sorted() const &;

private:
    std::vector<int> data;
};

Foo Foo::sorted() && {
    sort(data.begin(), data.end());
    std::cout << "sorted() &&" << std::endl;
    return *this;
}

Foo Foo::sorted() const & {
    std::cout << "sorted() const &" << std::endl;
    return Foo(*this).sorted();
}

Foo::Foo(const std::initializer_list<int> li) {
    for (auto &i : li) {
        data.push_back(std::move(i));
    }
}

Foo func() {
    return Foo({2, 5, 1, 4, 3});
}

int main(int argc, char const *argv[]) {
    Foo f1{1, 2, 3, 4, 5};
    f1.sorted();
    func().sorted();
    return 0;
}
