/*
 * `什么是类的静态成员？它有何优点？静态成员与普通成员有何区别？
 */

/*
 * 静态成员是指：与类本身直接相关，而跟类的对象不保持关联的特殊成员。
 *
 * 优点：
 * 有一些数据成员是所有类对象共享的，声明成static可以很方便做到共享。
 *
 * 区别：
 * 静态成员函数不包含this指针。
 * 静态数据成员可以是不完全类型。
 * 可以使用静态成员作为默认实参。
 */

int main(void) {
    return 0;
}
