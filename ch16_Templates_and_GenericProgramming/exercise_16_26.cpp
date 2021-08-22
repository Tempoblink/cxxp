/*
 * 假设NoDefault是一个没有默认构造函数的类，
 * 我们可以显式实例化vector<NoDefault>吗？如果不可以，解释为什么？
 */

/*
 * 显示实例化类模版会实例化所有成员函数，包括内联的成员函数。
 * vector的构造函数会使用元素类型的默认构造函数来对元素进行初始化，
 * 而Nodefault没有默认构造函数，从而导致编译错误。
 */

#include <iostream>
#include <vector>

class NoDefault {

public:
    NoDefault() = delete;
};

int main(int argc, char const* argv[])
{
  std::vector<NoDefault> novec;
  return 0;
}
