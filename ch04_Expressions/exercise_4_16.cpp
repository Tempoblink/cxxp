/*
 * 尽管下面的语句合法，但它们实际执行的行为可能和预期的不一样，为什么？应该如何修改？
 *
 * (a) if (p = getPtr() != 0 )         (b) if (i = 1024)
 */


/*
 * (a) if ((p = getPtr()) != 0)       (b) if(1024 == i)
 */

int main(void) {
    return 0;
}
