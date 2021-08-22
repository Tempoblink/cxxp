/*
 * 下列vector对象的定义又不正确的吗？如果有，请指出来，对于正确的，描述其执行结果；对于不正确的，说明其错误的原因。
 *
 * (a) vector<vector<int>> ivec;
 * (b) vector<string> svec = ivec;
 * (c) vector<string> svec(10, "null");
 */

/*
 * (a) 正确，定义一个空的vector，其元素类型是vector<int>。
 * (b) 不正确，容器中的对象类型不同。
 * (c) 正确，定义了一个内含10个"null"的字符串容器。
 */

int main(void) {
    return 0;
}
