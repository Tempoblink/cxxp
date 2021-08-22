/*
 * 假定Sales_data的构造函数不是explicit的，则下述定义将执行什么样的操作？
 *
 * string null_isbn("9-999-99999-9");
 * Sales_data item1(null_isbn);
 * Sales_data item2("9-999-99999-9");
 */

/*
 * string null_isbn("9-999-99999-9");
 * Sales_data item1(null_isbn);       直接使用null_isbn作为实参构造item1  调用 Sales_data(const std::string &);
 * Sales_data item2("9-999-99999-9"); 通过创建一个临时的string，将其作为实参构造item2，因为形参是一个常量引用，所以合法。
 */

int main(void) {
    return 0;
}
