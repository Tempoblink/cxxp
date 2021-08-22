/*
 * 在第316页的程序中，向下面语句这样调用insert是否合法？如果不合法，为什么？
 *
 * iter = vi.insert(iter, *iter++);
 */

/*
 * 不合法，因为参数的求值顺序不能确定，如果*iter++先被执行了，那么iter就已经移动到下一个位置了，但也可能不先被执行。因此插入的位置难以确定。
 */

int main(int argc, char const *argv[]) { return 0; }
