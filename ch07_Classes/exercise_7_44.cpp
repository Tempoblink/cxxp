/*
 * 下面这条声明合法吗？如果不，为什么？
 *
 * vector<NoDefault> vec(10);
 */

/* 
 * 不合法，因为vector的10个元素将执行值初始化，因此会调用默认构造函数，而NoDefault没有默认构造函数，因此是错误的。
 */

int main() {
    return 0;
}
