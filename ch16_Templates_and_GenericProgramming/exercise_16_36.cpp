/*
 * 进行下面的调用会发生什么：
 * template <typename T> void f1(T, T);
 * tempalte <typename T1, typename T2> void f2(T1, T2);
 * int i = 0, j = 42, *p1 = &i, *p2 = &j;
 * const int *cp1 = &i, *cp2 = &j;
 *
 * (a) f1(p1, p2);
 * (b) f2(p1, p2);
 * (c) f1(cp1, cp2);
 * (d) f2(cp1, cp2);
 * (e) f1(p1, cp1);
 * (f) f2(p1, cp1);
 */

/*
 * (a) 合法，void f1(int *,int *);
 * (b) 合法，void f1(int *,int *);
 * (c) 合法，void f1(const int *, const int *);
 * (d) 合法，void f2(const int *, const int *);
 * (e) 不合法，T被判断为int * 和const int * 都不能匹配调用。
 * (f) 合法，void f2(int *, const int *);
 */

int main(int argc, char const *argv[]) {
    return 0;
}
