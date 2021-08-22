/*
 * 如果sorted定义如下，会发生什么：
 *
 * Foo Foo::sorted() const & { return Foo(*this).sorted(); }
 */

/*
 * 会调用右值版本的sorted()
 */

int main(int argc, char const *argv[]) {
    return 0;
}
