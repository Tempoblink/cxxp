/*
 * 假设txt_size是一个无参数的函数，它的返回值是int。请回答下列那个定义是非法？为什么？
 *
 * unsigned buf_size = 1024;
 * (a) int ia[buf_size];              (b) int ia[4 * 7 - 14];
 * (c) int ia[txt_size];              (d) char st[11] = "fundamental";
 */

/*
 * (a) 不合法，因为buf_size不是常量表达式，不能作为数组的维度。
 * (b) 合法，常量表达式。
 * (c) 只有当text_size是constexpr函数时才合法。
 * (d) 不合法，空间不够容纳空字符。
 */

int main(void) {
    return 0;
}
