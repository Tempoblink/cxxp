/*
 * 下面调用中哪些是错误的（如果有的话）？如果调用合法，T的类型是什么？如果调用不合法，问题何在？
 *
 * template <typename T> T calc(T, int);
 * template <typename T> T fcn(T, T);
 * double d; float f; char c;
 * (a) calc(c, 'c');
 * (b) calc(d, f);
 * (c) fcn(c, 'c');
 * (d) fcn(d, f);
 */

/*
 * (a) 合法，T 为 char类型。 而'c'将整型提升为int
 * (b) 合法，T 为 double类型，f 将转换为int
 * (c) 合法，T 为 char类型。
 * (d) 非法，因为第一个实参类型为double，而第二实参是float。函数实参类型不一致，无法推断出模板实参。
 */

int main(int argc, char const *argv[]) {
    return 0;
}
