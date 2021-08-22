/*
 * 在类的定义中对于访问说明符出现的位置和次数有限定吗？
 * 如果有，是什么？什么样的成员应该定义在public说明符之后？
 * 什么样的成员应该定义在private说明符之后？
 */

/*
 * 访问说明限定符的出现位置和次数没有限定，
 * 每个访问说明符指定了接下来的成员的访问级别，其有效范围直到出现下一个访问说明符或者到达类的结尾处为止。
 *
 * 类的接口应该定义在public之后，类的实现细节（实现细节的成员函数及数据成员）应该定义在private说明符之后。
 */

int main(void) {
    return 0;
}