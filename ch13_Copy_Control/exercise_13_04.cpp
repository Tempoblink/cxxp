/*
 * 假定Point是一个类类型，它有一个public的拷贝构造函数，指出下面程序片段中哪些地方使用了拷贝构造函数：
 *
 * Point global;
 * Point foo_bar(Point arg) {
 *    Point local = arg, *heap = new Point(global);
 *    *heap = local;
 *    Point pa[4] = {local, *heap};
 *    return *heap;
 * }
 */

/*
 * Point arg  拷贝构造函数
 * Point local 拷贝构造函数
 * new Point global 拷贝构造函数
 * Point pa[4] = {local, *heap} 拷贝构造函数
 * return *heap 拷贝构造函数
 */

int main(int argc, char const *argv[]) {
    return 0;
}
