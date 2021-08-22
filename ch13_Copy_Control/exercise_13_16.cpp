/*
 * 如果f中的参数是const numbered&，将会怎样？这会改变输出结果吗？
 * 如果会改变，为什么？新的输出结果是什么？
 */

/*
 * 会改变，因为不会创建新的序号了。
 * 新的输出结果是三个不同的mysn，它们就是a, b, c的mysn。
 */

int main(int argc, char const *argv[]) {
    return 0;
}
