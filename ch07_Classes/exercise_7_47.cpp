/*
 * 说明接受一个string参数的Sales_data构造函数是否应该是explicit的，并解释这样做的优缺点。
 */

/*
 * 如果类的用户认为这样方便创建一个units_sold和revenue都为0的有意义的对象，那么就不需要是explicit的。
 * 优点：提供了一个隐式转换规则，从而方便书写，比如一个直接初始化式。
 * 缺点：只能应用于有一个参数的构造函数。
 */

int main(void) {
    return 0;
}
