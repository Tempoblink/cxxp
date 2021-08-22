/*
 * 如果我们将DebugDelete与unique_ptr一起使用，
 * 解释编译器将删除器处理为内联形式的可能方式。
 */

/*
 * shared_ptr 是运行时绑定删除器，unique_ptr 是编译时绑定删除器。
 * unique_ptr 有两个模版参数，一个是所管理的对象类型，一个是删除器类型。
 * 删除器是unique_ptr类型的一部分，unique_ptr避免了间接调用删除器的运行时开销
 * 而自定义的删除器还可以以内联的形式在类中。
 */

int main(int argc, char const *argv[]) {
    return 0;
}
