/*
 * vector将其单参数的构造函数定义成explicit的，而string则不是， 你觉得原因何在？
 */

/*
 * 如果vector可以有隐式转换，举个例子，这样的初始化语句是合法的：
 * vector<int> ivec = 10;
 * 意思就是初始化ivec为10个0, 表面意义不明。
 */

int main(void) {
    return 0;
}
