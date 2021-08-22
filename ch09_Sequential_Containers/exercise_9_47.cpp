/*
 * 编写程序，首先查找string"ab2c3d7R4E6"中的每个数字字符，然后查找其中每个字母字符。
 * 编写两个版本的程序，第一个要使用find_first_of，第二个要使用find_fisrt_not_of。
 */

#include <iostream>
#include <string>

void find_num(const std::string &s) {
  std::string::size_type pos = 0;
  std::string numbers("0123456789");
  while ((pos = s.find_first_of(numbers, pos)) != std::string::npos) {
    std::cout << "String at " << pos << " is " << s[pos] << std::endl;
    ++pos;
  }
}

void find_alpha(const std::string &s) {
  std::string::size_type pos = 0;
  std::string numbers("0123456789");
  while ((pos = s.find_first_not_of(numbers, pos)) != std::string::npos) {
    std::cout << "String at " << pos << " is " << s[pos] << std::endl;
    ++pos;
  }
}

int main(int argc, char const *argv[]) {
  std::string str("ab2c3d7R4E6");
  std::cout << "str = " << str << std::endl;
  find_num(str);
  find_alpha(str);
  return 0;
}
