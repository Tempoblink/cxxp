/*
 * 利用本节定义的变量，判断下列语句的运行结果。
 *
 * a = 42; b = 42; c = 42;
 * d = 42; e = 42; g = 42;
 */

/*
 * const int ci = i, &cr = ci;
 * auto b = ci; //b是一个int整数
 * auto c = cr; //c是一个int整数
 * auto d = &i; //d是一个int指针
 * auto e = &ci;//e是一个指向整型常量的指针
 * auto &g = ci; //g是一个int引用
 */


/*
 * a = 42; 结果是变量a的值变为42。
 * b = 42; 结果是变量b的值变为42。
 * c = 42; 结果是变量c的值变为42。
 * d = 42; 不合法的赋值，不能用整型值给指针赋值。
 * e = 42; 不合法的赋值，不能用整型值给指针赋值。
 * g = 42; 不合法的赋值，g是常量引用，无法修改其值。
 */

int main(void) {
    return 0;
}