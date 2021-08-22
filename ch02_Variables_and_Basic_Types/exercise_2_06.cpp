/*
 * 下面两组定义是否有区别，如果有，请叙述之：
 *
 * int month = 9, day = 7;
 * int month = 09, day = 07;
 */

/*
 * 第一行定义的是十进制整数。
 * 第二行中int mount = 09是非法的，9超出了八进制的表示范围；day = 07定义的是八进制整数。
 */

int main(void) {
    return 0;
}
