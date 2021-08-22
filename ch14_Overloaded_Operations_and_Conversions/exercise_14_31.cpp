/*
 *  我们的StrBlobPtr类没有定义拷贝构造函数、赋值运算符及析构函数，为什么？
 */

/*
 * 因为这个类不需要这些拷贝控制成员，它只用于访问资源，不用于管理资源。
 */

int main(int argc, char const *argv[]) {
    return 0;
}
