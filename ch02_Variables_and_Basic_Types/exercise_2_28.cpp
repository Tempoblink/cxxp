/*
 * 说明下面的这些定义是什么意思，挑出其中不合法的。
 *
 * (a) int i, *const cp;          (b) int *p1, *const p2;
 * (c) const int ic, &r = ic;     (d) const int *const p3;
 * (e) const int *p;
 */

/*
 * (a) 定义一个名为i的int型变量，cp定义错误，常量指针必须初始化。
 * (b) 定义一个名为p1的指向int的指针，p2定义错误，常量指针必须初始化。
 * (c) ic定义错误，const int必须初始化。r为常量引用。
 * (d) p3定义错误，指向常量对象的常量指针必须初始化。
 * (e) 定义一个名为p的指向const int的指针。
 */

int main(void) {
    return 0;
}
