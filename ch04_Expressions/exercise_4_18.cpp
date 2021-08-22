/*
 * 如果第132页那个输出vector对象元素的while循环使用前置递增运算符，将得到什么结果？
 */

/*
 * 如果vector里面没有负数，那么将会对尾后迭代器解引用，结果是未定义的。
 * 如果存在负数，则从第二个非负数开始输出直到遇到第一个负数，且输出该负数。
 */

#include <iostream>
#include <vector>

int main(void)
{
  std::vector<int> v{1,2,3,4,5,-1,6,7};
  auto pbeg = v.begin();
  while (pbeg != v.end() && *pbeg >= 0) {
    std::cout << *++pbeg << std::endl;
  }
  return 0;
}
