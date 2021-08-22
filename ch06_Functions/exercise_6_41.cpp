/*
 * 下面的哪个调用是非法的？为什么？哪个调用虽然合法但显然与程序员的初衷不符？为什么？
 *
 * char *init(int ht, int wd = 80, char bckgrnd = ' ');
 * (a) init(); (b) init(24, 10); (c) init(14, '*');
 */

/*
 * (a) 不合法，ht必须指定初始值。
 * (b) 合法。
 * (c) 合法，但与初衷不符。wd = static_cast<int>('*');
 */

int main(void) {
    return 0;
}
