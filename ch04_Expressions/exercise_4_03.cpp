/*
 * C++语言没有明确规定大多数二元运算符的求值顺序，给编译器优化留下了余地。
 * 这种策略实际上是在代码生成效率和程序潜在缺陷之间进行了权衡，你认为这可以接受吗？请说出你的理由。
 */

/*
 * 可以接受。因为C++更注重效率，这也是它的优势之一。只要搞明白求值顺序的概念，不触碰未定义的行为，就可以避免踩到陷阱。
 */

int main(void) {
    return 0;
}
