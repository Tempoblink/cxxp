/*
 * 下面的函数是否合法？如果不合法，为什么？如果合法，
 * 对可以传递的实参类型有什么限制（如果有的话）？返回类型是什么？
 *
 * template <typename It>
 * auto fcn3(It beg, It end) -> decltype(*beg + 0) {
 *      // 处理序列
 *      return *beg;  // 返回序列中的一个元素的拷贝。
 * }
 */

/*
 * decltype(*beg + 0)  其中*beg返回的时引用，而*beg + 0 表达式生成一个右值，因此decltype 返回该值的类型。
 * *beg所值元素支持 operato +()
 */

#include <iostream>
#include <vector>

template<typename It>
auto fcn3(It beg, It end) -> decltype(*beg + 0) {
    return *beg;
}

int main(int argc, char const *argv[]) {
    std::vector<int> ivec{1, 2, 3, 4, 5};
    auto f = fcn3(ivec.begin(), ivec.end());
    decltype(f) i;
    return 0;
}
