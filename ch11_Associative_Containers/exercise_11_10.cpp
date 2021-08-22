/*
 * 可以定义一个vector::iterator到int的map吗？ list::iterator到int的map呢？对于两种情况，如果不能，解释为什么。
 */

/*
 * vector版本的可以，list的不能。因为list的迭代器不支持<运算符。
 */

int main(int argc, char const *argv[]) {
    return 0;
}
