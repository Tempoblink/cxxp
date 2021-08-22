/*
 * 解释下面代码执行的结果：
 *
 * int *q = new int(42), *r = new int(100);
 * r = q;
 *
 * auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
 * r2 = q2;
 */

/*
 * r指向的内存空间未安全释放，并直接指向q的内存空间。
 *
 * r2原内存空间被安全释放，再指向q2的内存空间。
 */

int main(int argc, char const *argv[]) {
    return 0;
}
