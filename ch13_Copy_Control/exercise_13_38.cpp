/*
 * 我们并未使用拷贝和交换方式来设计Message的赋值运算符。你认为其原因是什么？
 */

/*
 * 拷贝和交换的方式适用于动态分配资源的场景，这样可以提高效率。
 * 而Message不是动态分配的，不适用这种场景。
 */

int main(int argc, char const *argv[]) {
    return 0;
}
