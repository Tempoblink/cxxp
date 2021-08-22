/*
 * 编写你自己的fact.cc和factMain.cc，这两个文件都应该包含上一个小节的练习中编写的Chapter6.h头文件。
 * 通过这些文件，理解你的编译器都是如何支持分离式编译的。
 */

#include <iostream>
#include "include/Chapter6.h"

int main(void)
{
  int n = 5;
  std::cout << n << "! is " << fact(n) << std::endl;
  return 0;
}
