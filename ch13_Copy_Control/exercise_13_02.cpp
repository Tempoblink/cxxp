/*
 * 解释为什么下面的声明是非法的：
 *
 * Sales_data::Sales_data(Sales_data rhs);
 */

/*
 * 拷贝构造函数的参数应该是一个本类型的引用，
 * 如果不是引用，那么对参数的初始化还会调用拷贝构造函数，如此则无限循环。
 */

int main(int argc, char const *argv[]) {
    return 0;
}
