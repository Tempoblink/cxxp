/*
 * 如果你将transform函数中的find替换为下标运算符，会发生什么情况？
 */

/*
 * 当前使用的GCC版本会编译报错，因为传入的map是一个const的，无法使用下标运算符进行插入元素的操作。
 */


int main(int argc, char const *argv[]) {
    return 0;
}
