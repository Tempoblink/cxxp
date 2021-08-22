/*
 * 编写一段程序，创建一个含有10个整数的vector对象，然后使用迭代器将所有元素的值
 * 都变成原来的两倍。输出vector对象的内容，检验程序是否正确。
 */

#include <iostream>
#include <vector>

int main(void)
{
  std::vector<int> ievc(10, 4);
  for (auto &i : ievc) {
    i *= i;
  }
  for (auto i : ievc) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
