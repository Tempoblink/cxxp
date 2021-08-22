/*
 * 假定你希望每次读取一个字符存入string中，而且知道至少需要读取100个字符，应该如何提高程序的性能？
 */

/*
 * 使用reserve(200)预留足够的空间。
 */

#include <iostream>
#include <ostream>
#include <string>

int main(int argc, char const *argv[]) {
  std::string str;
  str.reserve(200);
  std::cout << "str.size()\t = " << str.size() << std::endl;
  std::cout << "str.capacity()\t = " << str.capacity() << std::endl;
  for (int i = 0; i < 100; i++) {
    str += 'H';
  }
  std::cout << "str.size()\t = " << str.size() << std::endl;
  std::cout << "str.capacity()\t = " << str.capacity() << std::endl;
  std::cout << "str = " << str << std::endl;
  return 0;
}
