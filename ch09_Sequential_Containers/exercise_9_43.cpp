/*
 * 编写一个函数，接受三个string参数s、oldVal和newVal。
 * 使用迭代器及insert和erase函数将s中所有oldVal替换为newVal。
 * 测试你的程序，用它替换通用的简写形式，如，将"tho"替换为"though"，将"thru"替换为"through"。
 */

#include <iostream>
#include <string>

void func(std::string s, std::string oldVal, std::string newVal) {
  auto iter = s.begin();
  while (iter != s.end()) {
    std::string tmp(iter, iter + oldVal.size());
    if (tmp == oldVal) {
      iter = s.erase(iter, iter + oldVal.size());
      iter = s.insert(iter, newVal.begin(), newVal.end());
      iter += newVal.size();
      --iter;
    } else {
      ++iter;
    }
  }

  std::cout << "s = " << s << std::endl;
}

int main(int argc, char const *argv[]) {
  std::string s("tho I am tho");
  std::string oldVal("tho");
  std::string newVal("though");
  std::cout << "s = " << s << std::endl;
  func(s, oldVal, newVal);
  return 0;
}
