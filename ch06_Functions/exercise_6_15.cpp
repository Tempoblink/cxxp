/*
 * 说明find_char函数中的三个形参为什么是现在的类型，
 * 特别说明为什么s是常量引用而occurs是普通引用？
 * 为什么s和occurs是引用类型而c不是？
 * 如果令s是普通引用会发生什么情况？
 * 如果令occurs是常量引用会发生什么情况？
 */

/*
 * 字符串s为了避免拷贝，应当使用引用，又因为函数只读取s而不修改它，所以应当使用常量引用；
 * 将occurs定义成普通引用是因为需要修改其值并作为一个返回结果；
 * c只是一个char，传值比较方便。
 * s是普通引用的话也不会有错误，但没有必要；为了防止原始字符串被修改，所以建议常量引用。
 * occurs如果是常量引用则无法通过编译，因为函数需要修改其绑定对象的值。
 */

int main(void) {
    return 0;
}
