/*
 * 编写程序，探究在你的标准库实现中，vector是如何增长的。
 */

#include <iostream>
#include <ostream>
#include <vector>

int main(int argc, char const *argv[]) {
  std::vector<int> ivec;
  for (int i = 0; i < 10; i++) {
    ivec.push_back(i);
    std::cout << "ivec.size()\t = " << ivec.size() << std::endl
              << "ivec.capacity()\t = " << ivec.capacity() << std::endl;
  }
  return 0;
}
