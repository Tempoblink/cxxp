/*
 * 对于第312页中删除一个范围内的元素的程序，如果elem1与elem2相等会发生什么？
 * 如果elem2是尾后迭代器，或者elem1和elem2皆为尾后迭代器，又会发生什么？
 */

/*
 * 如果elem1与elem2相等、或者都是尾后迭代器，那么什么都不会发生
 * 如果elem2是尾后迭代器，则删除[elem1, elem2)范围内的元素
 * 如果elem1与elem2皆为尾后，与相等的情况一样。
 */

#include <iostream>
#include <list>

int main(int argc, char const *argv[]) {
  std::list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto it1 = lst.begin(), it2 = lst.begin();
  lst.erase(it1, it2);
  for (const auto &i : lst) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  it2 = lst.end();
  // lst.erase(it1, it2);
  // for (const auto &i : lst) {
  // std::cout << i << " ";
  // }
  // std::cout << std::endl;

  it1 = lst.end();
  lst.erase(it1, it2);
  for (const auto &i : lst) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
