/*
 * 当一个StrBlob对象销毁时会发生什么？一个StrBlobPtr对象销毁时呢？
 */

/*
 * StrBlob销毁时，其智能指针成员会被销毁，如果其引用计数为0，则会把其指向的对象也销毁。
 *
 * StrBlobPtr销毁时，其weak_ptr成员会被销毁，不会影响其绑定的智能指针的引用计数。
 */

int main(int argc, char const *argv[]) {
    return 0;
}
