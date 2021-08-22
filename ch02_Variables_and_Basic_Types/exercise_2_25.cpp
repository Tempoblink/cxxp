/*
 * 说明下列变量的类型和值。
 *
 * (a) int *ip , i, &r = i;
 * (b) int i, *ip = 0;
 * (c) int *ip, ip2;
 */


/*
 * (a) ip->int型指针  i->int型整数  r->指向i的引用
 * (b) i->int型整数   ip->int型指针，赋值初始化为空指针
 * (c) ip->int型指针  ip2->int型整数。
 *
 * 全局变量则默认初始化
 * 局部变量则为定义
 */


int main(void) {
    return 0;
}
