/*
 * 重写上一题的函数，这次使用一个下标和replace。
 */

#include <iostream>
#include <string>

void func(std::string s, std::string oldVal, std::string newVal) {
  auto iter = s.begin();
  while (iter != s.end()) {
    std::string tmp(iter, iter + oldVal.size());
    if (tmp == oldVal) {
      s.replace(iter, iter + oldVal.size(), newVal);
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
