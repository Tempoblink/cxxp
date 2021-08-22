/*
 * 已知有如下声明：
 *
 * void mainip(int, int);
 * double dobj;
 *
 * 请指出下列调用中每个类型转换的等级（参见6,6,1节，第219页）。
 * (a) mainip('a', 'z'); (b) mainip(55.4, dobj);
 */

/*
 * char -> int 类型提升   第三等级。
 * double -> int 算术转换 第四等级。
 */

int main(void) {
    return 0;
}
