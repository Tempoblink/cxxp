/*
 * 你会把下面的哪个声明和定义放在头文件中？哪个放在源文件中？为什么？
 *
 * (a) inline bool eq(const BigInt&, const BigInt&) { ... }
 * (b) void putValues(int *arr, int size);
 */

/*
 * (a) 放到头文件中，因为这是一个内联函数，它的多个定义必须完全一致，因此通常把内联函数定义在头文件中。
 * (b) 声明在头文件，定义在源文件。因为这样可以实现分离式编译（改动了函数的实现，不需要重新编译其它引用了此函数的源文件，见书本p186）。
 */

int main(void) {
    return 0;
}
