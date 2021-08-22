/*
 * 对于下面的这些语句，请说明对象被声明成了顶层const还是底层const？
 *
 * const int v2 = 0;            int v1 = v2;
 * int *p1 = &v1, &r1 = v1;
 * const int *p2 = &v2, *const p3 = &i, &r2 = v2;
 */

/*
 * v2 顶层const
 * p2 底层const
 * p3 顶层const  底层const
 * r2 底层const
 */

int main(void) {
    return 0;
}
