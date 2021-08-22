/*
 * 根据本节给出的变量定义，说明在下面的表达式中奖发生什么样的类型转换？
 *
 * (a) if (fval)      (b) dval = fval + ival;      (c) dval + ival * cval
 */

/*
 * fval : float -> bool
 * ival : int -> float     (fval+ival) : float -> double
 * cval : char -> int      (ival+cval) : int -> double
 */

int main(void) {
    return 0;
}
