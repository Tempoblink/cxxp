/*
 * 如果sorted定义如下，会发生什么：
 *
 * Foo Foo::sorted() const & {
 *    Foo ret(*this);
 *    return ret.sorted();
 * }
 */

/*
 * this 是左值，初始化了ret，而ret也是左值。
 * 因此ret.sorted()会递归调用该sorted()
 */

int main(int argc, char const *argv[]) {
    return 0;
}
