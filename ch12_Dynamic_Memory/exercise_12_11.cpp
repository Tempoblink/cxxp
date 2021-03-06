/*
 * 如果我们像下面这样调用process，会发生什么？
 *
 * process(shared_ptr<int>(p.get()));
 */

/*
 * 由于使用了另一个智能指针的底层数据创建了一个智能指针，
 * 当原智能指针被销毁（或解引用）的时候，会造成未定义的错误，
 * 因为其指向的动态内存已经被释放过了。
 */

int main(int argc, char const *argv[]) {
    return 0;
}
