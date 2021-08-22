/*
 * 对下面的代码解释每个调用是否合法。如果合法，T的类型是什么？如果不合法，为什么？
 * template <class T> int compare(const T&, const T&);
 * (a) compare("hi", "world");        (b) compare("bye", "dad");
 */

/*
 * (a) 非法
 * 因为模版支持的类型转换是const引用和数组指针，而该模版使用的是const引用，
 * (b) 合法，仅在数组的大小相同时，即N相等。
 * 对于字符串字面值常量应该是 const (&arr)[N] 的引用
 */

int main(int argc, char const *argv[]) {
    return 0;
}
