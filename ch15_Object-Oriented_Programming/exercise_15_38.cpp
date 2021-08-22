/*
 * 下面的声明合法吗？如果不合法，请解释原因；如果合法，请指出含义。
 * BinaryQuery a = Query("fiery") & Query("bird");
 * AndQuery a = Query("fiery") & Query("bird");
 * OrQuery a = Query("fiery") & Query("bird");
 */

/*
 * 不合法，BinaryQuery是一个抽象类，无法实例化
 *
 * 合法，生成一个AndQuery
 * 不合法，类型不一致 
 */

int main(int argc, char const *argv[]) {
    return 0;
}
