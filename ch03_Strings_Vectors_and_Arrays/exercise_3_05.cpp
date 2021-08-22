/*
 * 编写一段程序从标准输入中读入多个字符串并将它们连接在一起，输出连接成大字符串。
 * 然后修改上述程序，用空格把输入的多个字符串分隔开来。
 */

#include <iostream>
#include <string>

int main(void) {
    std::string word, sum;
    /* 
  while (std::cin >> word) {
      sum += word;
  }
  */
    while (std::cin >> word) {
        sum += word;
        sum += " ";
    }
    std::cout << "The string is: " << sum << std::endl;
    return 0;
}
