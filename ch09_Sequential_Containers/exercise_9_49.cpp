/*
 * 如果一个字母延伸到中线之上，如d或f，则称其有上出头部分(ascender)。
 * 如果一个字母延伸到中线之下，如p或q，则称其有下出头部分(descender)。
 * 编写程序，读入一个单词文件，输出最长的即不包含上出头部分，也不包含下出头部分的单词。
 */

// aceimnorsuvwxz

#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
  if (argc < 2)
    exit(1);
  std::ifstream readfile(argv[1], std::ifstream::in);
  if (!readfile)
    exit(1);
  std::string sub("aceimnorsuvwxz");
  std::string word, maxword;
  while (readfile >> word) {
    if ((word.find_first_not_of(sub) == std::string::npos) &&
        word.size() > maxword.size())
      maxword = word;
  }
  if (maxword.size()) {
    std::cout << "The max special word: " << maxword << std::endl;
  } else {
    std::cout << "Not found!" << std::endl;
  }
  return 0;
}
