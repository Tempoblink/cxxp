/*
 * 当我们将一个StrBlob赋值给另一个StrBlob时，会发生什么？赋值StrBlobPtr呢？
 */

/*
 * 赋值StrBlob时，把右侧的底层智能指针赋值给左侧的，左侧的底层智能指针引用计数递减，右侧的递增。
 *
 * 赋值StrBlobPtr时，把右侧的底层weak_ptr赋值给左侧的，不影响原双方智能指针的引用计数。
 */

int main(int argc, char const *argv[]) {
    return 0;
}
