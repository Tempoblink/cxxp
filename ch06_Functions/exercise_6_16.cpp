/*
 * 下面的这个函数虽然合法，但是不算特别有用。指出它的局限性并设法改善。
 *
 * bool is_empty(string &s) { return s.empty(); }
 */

/*
 * s由于不是常量引用，故而无法传入const string对象，
 * bool is_empty(const string &s) { return s.empty(); }
 */

int main(void) {
    return 0;
}
