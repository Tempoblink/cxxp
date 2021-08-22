/*
 * 下面的初始值是错误的，请找出问题所在并尝试修改它。
 *
 * struct X {
 *  X (int i, int j) : base(i), rem(base % j) {}
 *  int rem, base;
 * };
 */

/*
 * 成员的初始化顺序与它们在类定义中的出现顺序一致，rem的初始化在base之前，而rem初始化时base是为定义的，所以是错误的。
 */

struct X {
    X(int i, int j) : base{i}, rem(base % j) {}
    int base, rem;
};

int main(void) {
    return 0;
}
