/*
 * 举一个形参应该是引用类型的例子，再举一个形参不能是引用类型的例子。
 */

/*
 * 形参应该是引用：
 *
 * void read(istream &is)
 * {
 *  // ...
 *  }
 *
 * 形参不能是引用：
 *
 * 当形参会改变，且不应该影响实参时。
 *
 *  int sum(int n)
 *  {
 *    int sum = 0;
 *    while (n > 0) sum += n--;
 *    return sum;
 *  }
 */

int main(void) {
    return 0;
}
