/*
 * 对下面每条带标签的语句，解释发生了什么样的实例化（如果有的话）。
 * 如果一个模板被实例化，解释为什么；如果未实例化，解释为什么没有。
 * template <typename T> class Stack {};
 * void f1(Stack<char>);                       // (a)
 * class Exercise {
 *      Stack<double> &rsd;                    // (b)
 *      Stack<int> si;                         // (c)
 * };
 * int main() {
 *      Stack<char> *sc;	                     // (d)
 *      f1(*sc);                               // (e)
 *      int iObj = sizeof(Stack<string>);      // (f)
 * }
 */

/*
 * (a) Stack<char>的实例化
 * (b) Stack<double>的实例化
 * (c) Stack<int>的实例化
 * (d) 未实例化，因为之前Stack<char>已发生了所需的实例化
 * (e) 未实例化，因为之前Stack<char>已发生了所需的实例化
 * (f) Stack<string>的实例化
 */

int main(int argc, char const *argv[]) {
    return 0;
}
