/*
 * begin和cbegin两个函数有什么不同？
 */

/*
 * 不带c的迭代器都是重载过的，两个函数，一个是常量容器成员，一个非常量成员。
 * begin返回迭代器类型依赖于容器的类型，如果容器是const的，则迭代器是const_iterator，否则是iterator；cbegin返回的是const_iterator。
 */

int main(void) {
    return 0;
}
