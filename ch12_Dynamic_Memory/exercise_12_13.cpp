/*
 * 如果执行下面的代码，会发生什么？
 *
 * auto sp = make_shared<int>();
 * auto p = sp.get();
 * delete p;
 */

/*
 * 当sp被销毁(或解引用)的时候，由于其指向的动态内存已经被销毁过了，
 * 因此会出现未定义的错误。
 * 二次析构错误。
 */

int main(int argc, char const *argv[]) {
    return 0;
}
