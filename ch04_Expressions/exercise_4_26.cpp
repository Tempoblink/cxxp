/*
 * 在本节关于测验成绩的例子中，如果使用unsigned int作为quizl的类型会发生什么情况？
 */

/*
 * 由于unsigned int可能是16位的，因此右侧的操作数如果是27，则超过了这个位数，那么结果是未定义的。
 */

int main(void) {
    return 0;
}
