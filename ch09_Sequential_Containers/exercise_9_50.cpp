/*
 * 编写程序处理一个vector<string>，其元素表示整数值。
 * 计算vector中所有元素之和。
 * 修改程序，使之计算表示浮点值得string之和。
 */

#include <iostream>
#include <string>
#include <vector>

void cal_int(const std::vector<std::string> &svec) {
  int sum = 0;
  std::cout << "svec = ";
  for (const auto &i : svec) {
    std::cout << i << " ";
    sum += std::stoi(i);
  }
  std::cout << std::endl;
  std::cout << "Sum = " << sum << std::endl;
}

void cal_duble(const std::vector<std::string> &svec) {
  double sum = 0;
  std::cout << "svec = ";
  for (const auto &i : svec) {
    std::cout << i << " ";
    sum += std::stod(i);
  }
  std::cout << std::endl;
  std::cout << "Sum = " << sum << std::endl;
}

int main(int argc, char const *argv[]) {
  std::vector<std::string> svec = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
  cal_int(svec);
  cal_duble(svec);
  return 0;
}
