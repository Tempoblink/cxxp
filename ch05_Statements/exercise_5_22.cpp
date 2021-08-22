/*
 * 本节的最后一个例子跳到begin，其实使用循环能更好的完成该任务。
 * 重写这段代码，注意不再使用goto语句。
 *
 * begin:
 *        int sz = get_size();
 *        if(sz <= 0) {
 *            goto begin;
 *        }
 */

#include <iostream>


int get_size(void) {
    return 1;
}

int main(void) {
    int sz;
    do {
        sz = get_size();
    } while (sz <= 0);
    return 0;
}
