/*
 * 如果move、set和display函数返回类型不是Screen&而是Screen，则上一个练习中将会发生什么情况？
 */

/*
 * 第一个条输出的结果是一样的。
 * 然而这些操作不会影响原对象（因为仅仅操作于临时副本），因此第二条输出的仍然是原对象的初始内容。
 */

int main(void) {
    return 0;
}