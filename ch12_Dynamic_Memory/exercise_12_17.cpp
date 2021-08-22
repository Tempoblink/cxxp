/*
 * 下面的unique_ptr声明中，哪些是合法的，哪些可能导致后续的程序错误？解释每个错误的问题在哪里。
 *
 * int ix = 1024, *pi = &ix, *pi2 = new int(2048);
 * typedef unique_ptr<int> IntP;
 *
 * (a) IntP p0(ix);
 * (b) IntP p1(pi);
 * (c) IntP p2(pi2);
 * (d) IntP p3(&ix);
 * (e) IntP p4(new int(2048));
 * (f) IntP p5(p2.get());
 */

/*
 * (a) 不合法，p0只能指向一个内存空间。
 * (b) 不合法，p1指向了一个静态变量。
 * (c) 合法，但是pi2不能手动释放，否则发生未定义。
 * (d) 不合法，p1指向了一个静态变量的地址。
 * (e) 合法，正确初始化p4。。
 * (f) 不合法，p2.get()获得的指针不可以初始化智能指针. 
 */

#include <memory>

int main(int argc, char const *argv[]) {
    int ix = 1024, *pi = &ix, *pi2 = new int(2048);
    typedef std::unique_ptr<int> IntP;
    IntP p2(pi2);
    IntP p5(p2.get());
    return 0;
}
