/*
 * 类型int、long、long long和short的区别是什么？无符号类型和带符号类型的区别是什么？float和double的区别是什么？
 */

/*
 * int、long、long long和short它们的尺寸可能不一样，C++标准给出了最小尺寸要求，编译器可以给予更大的尺寸。
 * short <= int <= long <= long long
 *
 * 带符号类型可以表示正数、负数或0。
 * 无符号类型代表大于等于0的值。
 *
 * float和double的尺寸通常不一样，float通常有7个有效位，double通常有16个。
 */

int main(void) {
    return 0;
}
