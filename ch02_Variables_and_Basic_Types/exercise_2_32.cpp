/*
 * 下面的代码是否合法？如果非法。请设法将其修改正确。
 *
 * int null = 0, *p = null;
 */

/*
 * 不合法，p是指针，不能把int变量赋值给它。改为: int null = 0, *p = &null;
 */

int main(void) {
    return 0;
}
