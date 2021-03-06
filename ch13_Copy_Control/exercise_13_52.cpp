/*
 * 详细解释第478页中的HasPtr对象的赋值发生了什么？
 * 特别是，一步一步描述hp、hp2以及HasPtr的赋值运算符中的参数rhs的值发生了什么变化。
 */

/*
 * hp = hp2;
 * 由于hp2是一个左值，因此调用拷贝构造函数初始化operator=函数的形参，hp2本身不会发生变化。
 *
 * hp = std::move(hp2);
 * hp2经过move得到一个右值引用，因此会调用移动构造函数初始化operator=函数的形参，移动构造函数会修改hp2，使其处于无效状态。
 */

int main(int argc, char const *argv[]) {
    return 0;
}
