/*
 * 预测在你的查询主程序中何时会执行调用运算符。
 * 如果你的预测和实际不符，确认你理解了原因。
 */

/*
 * 当runQueries运行完毕的时候（用户输入q），
 * TextQuery析构，
 * shared_ptr的引用数量变为0，
 * 此时调用析构器的调用运算符。
 */

int main(int argc, char const *argv[]) {
    return 0;
}
