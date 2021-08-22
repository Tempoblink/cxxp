/*
 * 编写程序，从一个vector<char>初始化一个string。
 */

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
  // hello
  std::vector<char> cvec{'H', 'e', 'l', 'l', 'o'};
  std::string str(cvec.begin(), cvec.end());
  std::cout << "string = " << str << std::endl;
  return 0;
}
