/*
 * 给定下面的new表达式，你应该如何释放pa？
 *
 * int *pa = new int[10];
 */

/*
 * delete [] pa;
 */

int main(int argc, char const *argv[]) {
    int *pa = new int[10];
    delete[] pa;
    return 0;
}
