/*
 * 下列的vector对象各包含多少个元素？这些元素的值分别是多少？
 *
 * (a) vector<int> v1;              (b) vector<int> v2(10);
 * (c) vector<int> v3(10, 42);      (d) vector<int> v4{10};
 * (e) vector<int> v5{10, 42};      (f) vector<string> v6{10};
 * (g) vector<string> v7{10, "hi"};
 */

/*
 * (a) 0              (b) 10个值，0
 * (c) 10个值，42     (d) 1个值，10
 * (e) 2个值，10和42  (f) 10个值，空值符串
 * (g) 10个值，10个"hi" 字符串
 */
int main(void) {
    return 0;
}
