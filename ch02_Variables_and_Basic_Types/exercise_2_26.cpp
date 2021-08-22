/*
 * 下面哪些句子是合法的？如果有不合法的句子，请说明为什么？
 *
 * (a) const int buf;      (b) int cnt = 0;
 * (c) cosnt int sz = cnt; (d) ++cnt; ++sz;
 */

/*
 * (a) 不合法，必须初始化一个const变量。
 * (b) 合法。
 * (c) 合法。
 * (d) 不合法。sz为const变量，无法被修改。
 */

int main(void) {
    return 0;
}
