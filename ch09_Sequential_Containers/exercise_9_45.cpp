/*
 * 编写一个函数，接受一个表示名字的string参数和两个分别表示前缀（如Mr.或Ms.）和后缀（如Jr.或III）的字符串。
 * 使用迭代器及insert和append函数将前缀和后缀添加到给定的名字中，将生成新string返回。
 */

#include <iostream>
#include <string>

std::string func(std::string s, const std::string &prefix,
                 const std::string &suffix) {
  s.insert(s.begin(), prefix.begin(), prefix.end());
  s.append(suffix.begin(), suffix.end());
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
