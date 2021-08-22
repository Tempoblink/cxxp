/*
 * 在下面这段代码中为什么p合法而lp非法？
 * 
 * int i = 42;    void *p = &i;     long *lp = &i;
 */

/*
 * 因为类型是void*的指针可以指向任何类型的对象，而long*的指针只能指向long类型的对象。
 */

int main(void) {
    return 0;
}
