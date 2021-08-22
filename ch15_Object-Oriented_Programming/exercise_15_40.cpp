/*
 * 在OrQuery的eval函数中，如果rhs成员返回的是空集将发生什么？如果lhs是空集呢？如果lhs和rhs都是空集又将发生什么？
 */

/*
 * 程序正常运转，空集时，迭代器范围为空。
 * lhs 为空，创建的ret_lines也为空，
 * rhs为空，ret_lines不插入元素。
 */

int main(int argc, char const *argv[]) {
    return 0;
}
