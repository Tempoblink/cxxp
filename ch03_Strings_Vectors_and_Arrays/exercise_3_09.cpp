/*
 * 下面的程序有何作用？它合法吗？如果不合法，为什么？
 * string s;
 * cout << s[0] << endl;
 */

/*
 * 不合法，字符串为空，s[0]是未定义的。
 */

#include <iostream>
#include <string>

int main(void)
{
  std::string s;
  std::cout << s[0] << std::endl;
  return 0;
}
