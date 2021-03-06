/*
 * 在什么情况下表达式的静态类型可能与动态类型不同？
 * 请给出三个静态类型与动态类型不同的例子。
 */

/*
 * 当使用一个基类的引用或指针，实际绑定到的是一个派生类对象，并调用其虚函数时。其静态类型与动态类型不同。
 * print(ostream &os); // os绑定到的实参可能是一个ofstream对象，也可能是一个cout
 * OnDie(Obj *obj); // obj绑定到的是派生类的对象，具体是哪个派生类直到运行时才知道
 * m_logic->Update(); // m_logic是基类的指针，它可能绑定到了派生类的对象
 */

int main(int argc, char const *argv[]) {
    return 0;
}
