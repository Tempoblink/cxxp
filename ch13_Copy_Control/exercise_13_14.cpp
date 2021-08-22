/*
 * 假定numbered是一个类，它有一个默认构造函数，
 * 能为每个对象生成一个唯一的序号，保存在名为mysn的数据成员中。
 * 假定numbered使用合成的拷贝控制成员，并给定如下函数：
 * void f(numbered s) { cout << s.mysn << endl; }
 * 则下面代码输出什么内容？
 * numbered a, b = a, c = b;
 * f(a); f(b); f(c);
 */

/*
 * 类numbered 默认构造函数，合成拷贝控制
 * a -> 默认构造
 * b -> 拷贝构造
 * c -> 拷贝构造
 * a.mysn = b.mysn = c.mysn;
 *
 * f(a) -> 拷贝构造 
 * f(b) -> 拷贝构造
 * f(c) -> 拷贝构造
 * 三个函数内的局部变量 mysn相等
 * 输出内容相同。
 */

int main(int argc, char const *argv[]) {
    return 0;
}
