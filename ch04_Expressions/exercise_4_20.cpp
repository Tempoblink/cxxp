/*
 * 假设iter的类型是vector<string>::iterator，说明下面的表达式是否合法，表达式的含义是什么？如果不合法，错在何处？
 *
 * (a) *iter++;         (b) (*iter)++;          (c) *iter.empty();
 * (d) iter->empty();   (e) ++*iter;            (f) iter++->empty();
 */

/*
 * (a) 合法，此表达式先对iter执行后置递增运算，然后返回其原始副本，得到其解引用的值。
 * (b) 不合法。*iter的结果是string类型，string没有后置递增操作。
 * (c) 不合法，.运算符的优先级要高，所以会执行iter.empty()，但iter没有empty成员，故错误。
 * (d) 合法，调用了string的empty成员，判断其是否为空。
 * (e) 不合法，string没有前置递增操作。
 * (f) 合法，执行iter的后置递增操作，然后返回其原始副本，对其使用箭头运算符，调用string的empty成员，判断其是否为空。
 */

int main(void) {
    return 0;
}
