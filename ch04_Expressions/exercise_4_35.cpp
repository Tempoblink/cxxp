/*
 * 假如有如下的定义：
 *
 * char cval;        int ival;       unsigned int ui;
 * flaot fval;       double dval;
 *
 * 请回答在下面的表达式中发生了隐式类型转换吗？如果有，指出来。
 *
 * (a) cval = 'a' + 3;              (b) fval = ui - ival * 1.0;
 * (c) dval = ui * fval;            (d) cval = ival + fval + dval;
 */

/*
 * (a) 'a' : char -> int     ('a' + 3) : int -> char
 * (b) ival : int -> double  ui : unsigned -> double  (ui - ival * 1.0) : double -> float
 * (c) ui : unsigned -> float    (ui * fval) : float -> double
 * (d) ival : int ->float     (ival + fval) : float -> double  (ival + fval + double) double -> char
 */

int main(void) {
    return 0;
}
