/*
 * 当一个Query类型的对象被拷贝、移动、赋值或销毁时，将分别发生什么？
 */

/*
 * Query 拷贝使用合成的默认拷贝构造 -> share_ptr的拷贝函数， 成员share_ptr p被拷贝。
 * Query 移动使用合成的默认移动构造 -> share_ptr的移动函数， 原指针=nullptr，初始化给share_ptr p指针
 * Query 赋值使用合成的默认赋值构造 -> share_ptr的赋值函数， 成员share_ptr p赋值
 * Query 销毁使用合成的默认销毁函数 -> share_ptr的销毁函数。
 */

int main(int argc, char const *argv[]) {
    return 0;
}
