/*
 * 执行下述if语句后将发生什么情况？
 *
 * if(42 = i) // ...
 * if(i = 42) // ...
 */

/*
 * 第一条语句是错误的，赋值运算符的左侧必须是一个左值。
 *
 * 第二条语句判断i是否为0，若不是（事实上也不是），就执行if语句块。
 */

int main(void) {
    return 0;
}
