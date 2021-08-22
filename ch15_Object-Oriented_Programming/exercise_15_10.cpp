/*
 * 回忆我们在8.1节（第279页）进行的讨论，
 * 解释第284页中将ifstream传递给Sales_data的read函数的程序是如何工作的。
 */

/*
 * read函数接受的是istream&，
 * 它是一个基类的引用，
 * 可以动态绑定到派生类的对象（比如ifstream实例）上面，
 * 从而令派生类执行自己实现的虚函数版本。
 */

int main(int argc, char const *argv[]) {
    return 0;
}
