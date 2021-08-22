/*
 * 什么类型的引用可以绑定到下面的初始化器上？
 *
 * int f();
 * vector<int> vi(100);
 * int? r1 = f();
 * int? r2 = vi[0];
 * int? r3 = r1;
 * int? r4 = vi[0] * f();
 */

/*
 * int&& r1 = f();
 * int& r2 = v1[0];
 * int& r3 = r1;
 * int&& r4 = vi[0] * f();
 */

int main(int argc, char const *argv[]) {
    return 0;
}
