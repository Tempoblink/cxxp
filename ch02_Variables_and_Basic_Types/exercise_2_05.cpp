/*
 * 指出下述字面值的数据类型并说明每一组内几种字面值的区别：
 *
 * (a) 'a', L'a', "a", L"a"
 * (b) 10, 10u, 10L, 10uL, 012, 0xC
 * (c) 3.14, 3.14f, 3.14L
 * (d) 10, 10u, 10., 10e-2
 *
 * (a) 'a'的类型是char，L‘a’的类型是wchar_t，”a“的类型是以空字符结尾的char数组，L"a"的类型是以空字符结尾的wchar_t数组。
 * (b) 10的类型是int，10u的类型是unsigned int，10L的类型是long，10uL的类型是unsigend long，012的类型是int，是一个用八进制表示的整数；0xC的类型是int，是一个用十六进制表示的整数。
 * (c) 3.14的类型是double，3.14f的类型是float，3.14L的类型是long double。
 * (d) 10的类型是int，10u的类型是unsigned int，10.的类型是double，10e-2的类型是double。
 */

int main(void) {
    return 0;
}
