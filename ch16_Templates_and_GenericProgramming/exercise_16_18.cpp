/*
 * 解释下面每个函数模板声明并指出它们是否非法。更正你发现的每个错误。
 *
 * (a) template<typename T, U, typename V> void f1(T, U, V);
 * (b) template<typename T> T f2(int &T);
 * (c) inline template<typename T> T foo(T, unsigned int*);
 * (d) template<typename T> f4(T, T);
 * (e) typedef char Ctype;
 *     template<typename Ctype> Ctype f5(Ctype a);
 */

/*
 * (a) 非法，
 *     template<typename T, typename U, typename V> void f1(T, U, V);
 * (b) 非法，T为类型名称，非变量名称。
 *     template<typename T> T f2(int&);
 * (c) 非法，inline在模版申明之后。
 *     template<typename T> inline T foo(T, unsigned int*);
 * (d) 非法，无返回类型。
 *     template<typename T> void f4(T, T); 
 * (e) 合法，但是类型名Ctype 隐藏了类型别名。
 */

int main(int argc, char const *argv[]) {
    return 0;
}
