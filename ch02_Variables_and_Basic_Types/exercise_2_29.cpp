/*
 * 假设已有上一个练习中定义的那些变量，则下面的哪些语句是合法的？请说明原因。
 *
 * (a) i = ic;           (b) p1 = p3;
 * (c) p1 = &ic;         (d) p3 = &ic;
 * (e) p2 = p1;          (f) ic = *p3;
 */

/*
 * (a) 合法。
 * (b) 不合法，p3指向了const int，而p1不能指向const int。
 * (c) 不合法，p1不能指向const int。
 * (d) 不合法，p3不能指向const int。
 * (e) 不合法，p2是常量，不能修改其值。
 * (f) 不合法，ic是常量，不能修改其值。
 */

int main(void) {
    return 0;
}
