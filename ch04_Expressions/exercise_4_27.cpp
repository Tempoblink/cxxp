/*
 * 下列表达式的结果是什么？
 *
 * unsigned long u11 = 3, ul2 = 7;
 * (a) ul1 & ul2        (b) ul1 | ul2
 * (c) ul1 && ul2       (d) ul1 || ul2
 */

/*
 * ul1        00000011
 * ul2        00000111
 *
 * (a)    00000011
 * (b)    00000111
 * (c)    00000001
 * (d)    00000001
 */

int main(void) {
    return 0;
}
