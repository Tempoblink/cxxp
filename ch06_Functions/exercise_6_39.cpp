/*
 * 说明在下面的每组声明中第二条声明语句是何含义。如果有非法的声明，请指出来。
 *
 * (a) int calc(int, int); int calc(const int, const int);
 * (b) int get(); double get();
 * (c) int *reset(int *); double *reset(double *);
 */

/*
 * (a) 不合法，传入顶层const版本的函数声明，本质上与第一个一样。
 * (b) 不合法，形参和第一个一样。
 * (c) 传入指向double类型的指针，与第一个明显不同，故是一个合法的重载函数。
 */

int main(void) {
    return 0;
}
