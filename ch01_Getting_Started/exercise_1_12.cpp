/*
 * 下面的for循环完成了什么功能？sum的终值是多少？
 * int sum = 0;
 * for (int  i = -100; i <= 100; ++i)
 * {
 *  sum += i;
 * }
 *
 */

/*
 * sum = 0
 */

#include <iostream>

int main(void) {
  int sum = 0;
  for (int i = -100; i <= 100; i++) {
    sum += i;
  }
  std::cout << "The sum is: " << sum << std::endl;
  return 0;
}
