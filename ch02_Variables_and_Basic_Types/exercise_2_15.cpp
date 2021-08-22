/*
 * 下面的哪个定义是不合法的？为什么？
 * (a) int ival = 1.01;     (b) int &rval1 = 1.01;
 * (c) int &rval2 = ival;   (d) int &rval3;
 */

/*
 * (b) 引用只能绑定在对象上，而不能与字面值或某个表达式的计算结果绑定在一起。
 * (d) 引用必须被初始化。
 */

int main(void) {
    return 0;
}
