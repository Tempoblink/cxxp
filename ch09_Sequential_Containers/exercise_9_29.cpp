/*
 * 假定vec包含25个元素，那么vec.resize(100)会做什么？如果接下来调用vec.resize(10)会做什么？
 */

/*
 * 首先会将容器大小调整为100个元素，新加的元素全部值初始化；然后将容器大小调整为10，这会删除掉后面的90个元素。
 */

int main(int argc, char const *argv[]) { return 0; }
