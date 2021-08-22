/*
 * 我们为什么为Disc_quote定义一个默认构造函数？
 * 如果去除该构造函数的话会对Bulk_quote的行为产生什么影响？
 */

/*
 * 由于Disc_quote定义了另一个版本的构造函数，合成版本的默认构造函数将不会被定义，
 * 这样，Bulk_quote就无法默认初始化，因为其基类没有默认构造函数。
 * 当基类的默认构造函数是被删除的，则派生类中的默认构造函数也是被删除的。
 */

int main(int argc, char const *argv[]) {
    return 0;
}
