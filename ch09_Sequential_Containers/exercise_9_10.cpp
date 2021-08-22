/*
 * 下面4个对象分别是什么类型？
 *
 * vector<int> v1;
 * const vector<int> v2;
 * auto it1 = v1.begin(), it2 = v2.begin();
 * auto it3 = v1.cbegin(), it4 = v2.cbegin();
 */

/*
 * it1 是 iterator          it2 是 const_iterator
 * it3 是 const_iterator    it4 是 const_iterator
 */

int main(void) {
    return 0;
}
