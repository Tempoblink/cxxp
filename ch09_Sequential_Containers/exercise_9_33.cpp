/*
 * 在本节最后一个例子中，如果不将insert的结果赋予begin，将会发生什么？
 * 编写程序，去掉此赋值语句，验证你的答案。
 */

/*
 * begin将失效，继续使用的结果是灾难性的。因为在begin之前插入了元素，其后的迭代器
 *（包括begin）都将失效。
 */

#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
  std::vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto begin = ivec.begin();
  while (begin != ivec.end()) {
    ++begin;
    v.insert(begin, 42);
    ++begin;
  }
  return 0;
}
