/*
 * 为什么不定义const版本的递增和递减运算符？
 */

/*
 * 因为这些运算符修改对象，和const版本的成员函数矛盾。
 */

int main(int argc, char const *argv[]) {
    return 0;
}
