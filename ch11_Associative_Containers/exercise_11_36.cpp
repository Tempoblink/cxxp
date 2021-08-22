/*
 * 我们的程序并没有检查输入文件的合法性。
 * 特别是，它假定转换规则文件中的规则都是有意义的。
 * 如果文件中的某一行包含一个关键字、一个空格，然后就结束了，会发生什么？
 * 预测程序的行为并进行验证，再与你的程序进行比较。
 */

/*
 * 只有一个空格的版本没有影响。
 *
 * 只有一个关键字的版本抛出异常并崩溃。
 * runtime_error
 */

int main(int argc, char const *argv[]) {
    return 0;
}
