/*
 * 给定下面的模板，如果我们对一个像42这样的字面常量调用g，
 * 解释会发生什么？如果我们对一个int类型的变量调用g呢？
 * template<typename T> void g(T&& val) { vector<T> v; }
 */

/*
 * 42:
 *    T -> int  std::vector<int> v;
 * int i:
 *    T -> int& std::vector<int&> v; 引用不是对象，创建非法。
 */

int main(int argc, char const *argv[]) {
    return 0;
}
