/*
 * 下面哪些论断是不正确的？为什么？
 *
 * (a) 一个类必须至少提供一个构造函数。
 * (b) 默认构造函数是参数列表为空的构造函数。
 * (c) 如果对于类来说不存在有意义的默认值，则类不应该提供默认构造函数。
 * (d) 如果类没有定义默认构造函数，则编译器将为其生成一个并把每个数据成员初始化成相应类型的默认值。
 */

/*
 * (a) 不正确，不提供的话，编译器会自动合成一个。
 * (b) 不正确，还可以有默认实参的构造函数（所有形参都有一个默认实参），也可以作为默认构造函数。
 * (c) 不正确，某些类不能依赖合成的默认构造函数（p236）。
 * (d) 不正确。只有当类没有声明任何构造函数时，编译器才会自动生成默认构造函数（p236）。
 */

int main(void) {
    return 0;
}
