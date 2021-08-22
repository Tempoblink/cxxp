/*
 * 类指针的HasPtr版本会从swap函数受益吗？如果会，得到了什么益处？如果不是，为什么？
 */

/*
 * 不会。因为类指针的版本共享底层数据(std::string *)，不需要分配额外的内存——这正是swap可以优化的地方。
 */

int main(int argc, char const *argv[]) {
    return 0;
}
