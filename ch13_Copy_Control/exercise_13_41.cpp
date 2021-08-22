/*
 * 在push_back中，我们为什么在construct调用中使用后置递增运算？
 * 如果使用前置递增运算的话，会发生什么？
 */

/*
 * 因为first_free是数组中首个可构造的内存，如果使用前置递增，将返回递增后的副本，那么构造的内存就错了。
 */

int main(int argc, char const *argv[]) {
    return 0;
}
