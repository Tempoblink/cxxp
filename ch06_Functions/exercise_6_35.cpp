/*
 * 在调用factorial函数时，为什么我们传入的值是val-1而非val--？
 */

/*
 * 这样做的结果是未定义的，因为不知道乘法两边的值到底是多少。
 *
 * 也就是 factorial(val--) * val 表达式中，不知道乘法两边的表达式谁先计算。
 *
 * 而且val将永远作为factorial的参数（而不会改变），因此这将是一个无限递归。
 */

int main(void) {
    return 0;
}
