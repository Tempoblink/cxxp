/*
 * 解释swap(HasPtr&, HasPtr&)中对swap的调用不会导致递归循环。
 */

/*
 * 因为函数内调用的swap版本不是主调函数的swap版本。
 * swap调用应该都是未加限定的，如果存在类型特定的swap版本，其匹配程度会优于std中定义的版本。
 */

int main(int argc, char const *argv[]) {
    return 0;
}
