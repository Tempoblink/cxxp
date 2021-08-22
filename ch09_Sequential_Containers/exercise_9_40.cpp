/*
 * 如果上一题中的程序读入了256个词，在resize之后容器的capacity可能是多少？
 * 如果读入了512个，1000个或1048个词呢？
 */

#include <iostream>
#include <ostream>
#include <string>
#include <vector>

void func(std::vector<std::string> &svec, int val) {
  std::string word = "H";
  for (int i = 0; i < val; i++) {
    svec.push_back(word);
  }
  svec.resize(svec.size() + svec.size() / 2);
  std::cout << "val\t = " << val << std::endl;
  std::cout << "svec.size()\t = " << svec.size() << std::endl;
  std::cout << "svec.capacity()\t = " << svec.capacity() << std::endl;
  svec.clear();
}

int main(int argc, char const *argv[]) {
  std::vector<std::string> svec;
  svec.reserve(1024);
  func(svec, 256);
  func(svec, 512);
  func(svec, 1000);
  func(svec, 1048);
  return 0;
}
