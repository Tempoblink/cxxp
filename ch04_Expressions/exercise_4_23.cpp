/*
 * 因为运算符的优先级问题，下面这条表达式无法通过编译。根据4.12节中的表（第147页）指出它的问题在哪里？应该如何修改？
 *
 * string s = "word";
 * string pl = s + s[s.size() - 1] == 's' ? "" : "s";
 */

/*
 * 加法的优先级要高于条件运算符，因此这条表达式把 s + s[s.size() - 1] 结合在一起，
 * 结果是一个string，然后和's'做比较，但是string不能和一个字符做比较，所以报错。
 */

#include <iostream>
#include <string>

int main(void) {
    std::string s = "word";
    std::string p1 = s + (s[s.size() - 1] == 's' ? "" : "s");
    std::cout << "p1 = " << p1 << std::endl;
    return 0;
}
