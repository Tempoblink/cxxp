/*
 * string和vector都定义了重载的==以比较各自的对象，
 * 假设svec1和svec2是存放string的vector，
 * 确定在下面的表达式中分别使用了哪个版本的==？
 * (a) "cobble" == "stone"
 * (b) svec1[0] == svec2[0]
 * (c) svec1 = svec2
 * (d) svec1[0] == "stone"
 */

/*
 * (a) 内置const char *  比较两个字符串的地址。
 * (b) string 的
 * (c) vector 的
 * (d) string 的
 */

int main(int argc, char const *argv[]) {
    return 0;
}
