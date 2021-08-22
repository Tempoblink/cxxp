/*
 * 下面哪条声明语句是不正确的？请解释原因。
 *
 * class Base { ... };
 * (a) class Derived : public Derived { ... };
 * (b) class Derived : private Base { ... };
 * (c) class Derived : public Base;
 */

/*
 * (a) 错误，一个类不能派生它本身
 * (b) 正确
 * (c) 错误，派生列表不能出现在声明处。
 */

int main(int argc, char const *argv[]) {
    return 0;
}
