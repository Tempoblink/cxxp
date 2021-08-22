/*
 * 使用下面代码定义的ia，将ia拷贝到一个vector和一个list中。
 * 使用单迭代器版本的erase从list中删除奇数元素，从vector中删除偶数元素。
 *
 * int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
 */

#include <iostream>
#include <iterator>
#include <list>
#include <vector>

int main(int argc, char const* argv[]) {
  int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
  std::vector<int> ivec(std::begin(ia), std::end(ia));
  std::list<int> ilist(std::begin(ia), std::end(ia));

  auto start1 = ivec.begin();
  while (start1 != ivec.end()) {
    if (*start1 % 2 == 0)
      start1 = ivec.erase(start1);
    else
      ++start1;
  }
  std::cout << "ivec\t = ";
  for (const auto& i : ivec) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  auto start2 = ilist.begin();
  while (start2 != ilist.end()) {
    if (*start2 % 2 != 0)
      start2 = ilist.erase(start2);
    else
      ++start2;
  }
  std::cout << "ilist\t = ";
  for (const auto& i : ilist) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
