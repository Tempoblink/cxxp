/*
 * 假定vi是一个保存int的容器，其中有偶数值也有奇数值，
 * 分析下面循环的行为，然后编写程序验证你的分析是否正确。
 *
 *  iter = vi.begin();
 *  while (iter != vi.end())
 *     if (*iter % 2)
 *        iter = vi.insert(iter, *iter);
 *     ++iter;
 */

/*
 * 死循环，在一个地方无限插入该数。
 */

#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
  std::vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto iter = vi.begin();
  while (iter != vi.end()) {
    if (*iter % 2) {
      iter = vi.insert(iter, *iter);
      iter += 2;
    } else {
      ++iter;
    }
  }
  for (const auto &i : vi)
    std::cout << i << " ";
  std::cout << std::endl;
  return 0;
}
