/*
 * 解释下面这个循环的含义。
 *
 * constexpr int size = 5;
 * int ia[size] = {1, 2, 3, 4, 5};
 * for (int *ptr = ia, ix = 0; 
 * ix != size && ptr != ia + size; 
 * ++ix, ++ptr) {...}
 */

/*
 * 遍历ia数组，ix随遍历的顺序增长。
 */

int main(void) {
    return 0;
}
