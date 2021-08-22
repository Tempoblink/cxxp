/*
 * 编写函数，接受一个forward_list<string>和两个string共三个参数。
 * 函数应在链表中查找第一个string，并将第二个string插入到紧接着第一个string之后的位置。
 * 如第一个string未在链表中，则将第二个string插入到链表末尾。
 */

#include <forward_list>
#include <iostream>
#include <string>

void func(std::forward_list<std::string> &flist, const std::string &str1,
          const std::string &str2) {
  auto prev = flist.before_begin();
  auto cur = flist.begin();
  bool find = false;
  while (cur != flist.end()) {
    if (*cur == str1) {
      find = true;
      prev = cur;
      cur = flist.insert_after(cur, str2);
    } else {
      prev = cur;
      ++cur;
    }
  }
  if (!find) {
    flist.insert_after(prev, str2);
  }
}

int main(int argc, char const *argv[]) {
  std::forward_list<std::string> flist = {"Hello", "Hi", "H",  "h",
                                          "h",     "H",  "Hi", "Hello"};
  std::string str1 = "H";
  std::string str2 = "This is a add string.";
  func(flist, str1, str2);
  for (const auto &i : flist) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
