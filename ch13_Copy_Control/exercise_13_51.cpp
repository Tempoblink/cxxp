/*
 * 虽然unique_ptr不能拷贝，但我们在12.1.5节（第418页）中编写了一个clone函数，
 * 它以值方式返回一个unique_ptr。
 * 解释为什么函数是合法的，以及为什么它能正确工作。
 */

/*
 * 因为这里的源unique_ptr即将销毁，是一个右值引用，执行的是移动操作。
 */

int main(int argc, char const *argv[]) {
    return 0;
}
