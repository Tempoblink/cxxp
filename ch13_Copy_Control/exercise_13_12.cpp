/*
 * 在下面的代码片段中会发生几次析构函数调用？
 *
 * bool fcn(const Sales_data *trans, Sales_data accum) {
 *    Sales_data item1(*trans), item2(accum);
 *    return item1.isbn() != item2.isbn();
 * }
 */

/*
 * item1 item2 accum  ---> 调用Sales_data的析构函数
 * iterm1.isbn()  iterm2.isbn()   ---> 临时变量调用std::string的析构函数
 */

int main(int argc, char const *argv[]) {
    return 0;
}
