/*
 * 第316页中删除偶数值元素并复制奇数值元素的程序不能用于list或forward_list。
 * 为什么？修改程序，使之也能用于这些类型。
 */

/*
 * list的迭代器不支持+=2这样的算术运算
 * forward_list并未定义insert和erase成员
 */

#include <forward_list>
#include <iostream>
#include <list>
#include <vector>

void make_list(std::list<int> &list) {
  auto iter = list.begin();
  while (iter != list.end()) {
    if (*iter % 2) {
      iter = list.insert(iter, *iter);
      ++iter;
      ++iter;
    } else {
      iter = list.erase(iter);
    }
  }

  for (const auto &i : list)
    std::cout << i << " ";
  std::cout << std::endl;
}

void make_forward_list(std::forward_list<int> &flist) {
  auto prev = flist.before_begin();
  auto cur = flist.begin();
  while (cur != flist.end()) {
    if (*cur % 2) {
      cur = flist.insert_after(cur, *cur);
      prev = cur++;
    } else {
      cur = flist.erase_after(prev);
    }
  }

  for (const auto &i : flist)
    std::cout << i << " ";
  std::cout << std::endl;
}

int main(int argc, char const *argv[]) {
  std::list<int> list{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::forward_list<int> flist{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  make_list(list);
  make_forward_list(flist);
  return 0;
}
