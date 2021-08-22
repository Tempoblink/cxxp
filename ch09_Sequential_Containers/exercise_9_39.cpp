/*
 * 解释下面程序片段做了什么？
 *
 * vector<string> svec;
 * svec.reserve(1024);
 * string word;
 * while (cin >> word)
 *    svec.push_back(word);
 * svec.resize(svec.size() + svec.size()/2);
 */

/*
 * 如果需求大于当前容量，reserve至少分配与需求一样大的内存空间（可能更大）
 *
 * 如果需求小于或等于当前容量，reserve什么也不做。
 */

int main(int argc, char const *argv[]) { return 0; }
