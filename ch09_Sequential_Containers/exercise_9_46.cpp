/*
 * 重写上一题的函数，这次使用位置和长度来管理string，并只使用insert。
 */

#include <iostream>
#include <string>

std::string func(std::string s, const std::string &prefix,
                 const std::string &suffix) {
  s.insert(0, prefix);
  s.append(suffix);
  return s;
}

int main(int argc, char const *argv[]) {
  std::string name = "Jake";
  std::string prefix = "Captain.";
  std::string suffix = "III";
  std::cout << "Who ?" << std::endl;
  std::cout << func(name, prefix, suffix) << std::endl;
  return 0;
}
