/*
 * 使用stack处理括号化的表达式。当你看到一个左括号，将其记录下来。
 * 当你在一个左括号之后看到一个右括号，从stack中pop对象，直到遇到左括号，将左括号也一起弹出栈。
 * 然后将一个值（括号内的运算结果）push到栈中，表示一个括号化的（子）表达式处理完毕，被其运算结果所替代。
 */

#include <cctype>
#include <iostream>
#include <ostream>
#include <stack>
#include <string>

int mix(const int &num1, const int &num2, const std::string s);
void cal(std::stack<std::string> &st, std::stack<int> &num);

int main(int argc, char const *argv[]) {
  std::stack<std::string> st;
  std::stack<int> n;
  std::string cur;
  while (std::cin >> cur) {
    if (cur == "(" || cur == "*" || cur == "/") {
      st.push(cur);
    } else if (cur == "+" || cur == "-") {
      if (!st.empty() && (st.top() == "*" || st.top() == "/"))
        cal(st, n);
      st.push(cur);
    } else if (cur == ")") {
      while (st.top() != "(") {
        cal(st, n);
      }
      st.pop();
    } else {
      n.push(std::stoi(cur));
    }
  }
  while (!st.empty()) {
    cal(st, n);
  }
  std::cout << n.top() << std::endl;
  return 0;
}

int mix(const int &num1, const int &num2, const std::string s) {
  int num = 0;
  switch (s[0]) {
  case '+':
    num = num1 + num2;
    break;
  case '_':
    num = num1 - num2;
    break;
  case '*':
    num = num1 * num2;
    break;
  case '/':
    num = num1 / num2;
    break;
  }
  return num;
}

void cal(std::stack<std::string> &st, std::stack<int> &num) {
  int num1, num2;
  num2 = num.top(), num.pop();
  num1 = num.top(), num.pop();
  num1 = mix(num1, num2, st.top()), st.pop();
  num.push(num1);
}
