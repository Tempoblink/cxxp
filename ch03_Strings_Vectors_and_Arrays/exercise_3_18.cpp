/*
 * 下面的程序合法吗？如果不合法，你准备如何修改？
 *
 * vector<int> ivec;
 * ievc[0] = 42;
 */

/*
 * 不合法，vector对象的下标运算符只能访问已存在的元素，不能用于添加元素。
 */

#include <iostream>
#include <vector>

int main(void)
{
  std::vector<int> ivec;
  ivec.push_back(42);
  std::cout << ivec[0] << std::endl;
  return 0;
}
