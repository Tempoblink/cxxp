/*
 * protected访问说明符与private有何区别？
 */

/*
 * 被protected说明的成员，可以使其在它的派生类中被访问，而禁止其他用户访问。
 * 被private说明的成员，既不能在其派生类中被访问，也不能被其他用户访问。
 */

int main(int argc, char const *argv[]) {
    return 0;
}
