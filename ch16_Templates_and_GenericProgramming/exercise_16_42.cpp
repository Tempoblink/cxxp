/*
 * 对下面的每个调用，确定T和val的类型：
 * template<typename T> void g(T&& val);
 * int i = 0; const int ci = i;
 *  (a) g(i);
 *  (b) g(ci);
 *  (c) g(i * ci);
 */

/*
 * (a) T -> int &   val-> int & && -> int &;
 * (b) T -> const int &  val -> const int & && -> const int &;
 * (c) T -> int  val -> int&&;
 */

int main(int argc, char const *argv[]) {
    return 0;
}
