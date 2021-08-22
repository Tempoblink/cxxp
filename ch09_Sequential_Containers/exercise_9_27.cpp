/*
 * 编写程序，查找并删除forward_list<int>中的奇数元素。
 */

#include <forward_list>
#include <iostream>

int main(int argc, char const* argv[]) {
  std::forward_list<int> flist = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto prev = flist.before_begin();
  auto cur = flist.begin();
  while (cur != flist.end()) {
    if (*cur % 2 != 0) {
      cur = flist.erase_after(prev);
    } else {
      prev = cur;
      ++cur;
    }
  }

  for (const auto& i : flist) std::cout << i << " ";
  std::cout << std::endl;
  return 0;
}
