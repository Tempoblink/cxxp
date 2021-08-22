/*
 * 设计一个类，它有三个unsigned成员，分别表示年、月、日。
 * 为其编写构造函数，接受一个表示日期的string参数。
 * 你的构造函数应该能处理不同数据格式，
 * 如January 1, 1990、1/1/1990、Jan 1 1990等。
 */

#include <algorithm>
#include <cctype>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

const static std::vector<std::string> MONTHS{
    "January", "February", "March",     "April",   "May",      "June",
    "July",    "August",   "September", "October", "November", "December"};

const static std::vector<std::string> MONS{"Jan", "Feb", "Mar", "Apr",
                                           "May", "Jun", "Jul", "Aug",
                                           "Sep", "Oct", "Nov", "Dec"};
const static std::string numbers("0123456789");

class Date {
  unsigned m_year;
  unsigned m_month;
  unsigned m_day;

public:
  Date() = default;
  Date(std::string);

  friend void print(std::ostream &, const Date &);
};

void print(std::ostream &os, const Date &d) {
  os << "Year = " << d.m_year << std::endl
     << "Month = " << d.m_month << std::endl
     << "Day = " << d.m_day << std::endl;
}

void make_month(std::string &s, const std::vector<std::string> &m) {
  std::string::size_type f = 0;
  for (decltype(m.size()) i = 0; i < m.size(); i++) {
    if ((f = s.find(m[i])) != std::string::npos) {
      s.replace(f, f + m[i].size() - 1, std::to_string(i + 1));
      return;
    }
  }
}

Date::Date(std::string s) {
  std::string::size_type f = 0, *p = &f;
  // January 1, 1990、1/1/1990、Jan 1 1990
  if ((f = s.find(',')) != std::string::npos) {
    make_month(s, MONTHS);
     s.erase(f, 1);
    
  } else if (s.find('/') != std::string::npos) {
    while ((f = s.find('/')) != std::string::npos) {
      s.replace(f, f, " ");
    }
  } else {
    make_month(s, MONS);
  }
  // 1 1 1900    1 1 1990  1 1 1900
  m_month = std::stoi(s, p);
  s = s.substr(*p + 1);
  m_day = std::stoi(s, p);
  s = s.substr(*p + 1);
  m_year = std::stoi(s.substr(s.find_first_of(numbers)));
}
int main(int argc, char const *argv[]) {
  Date d1("May 3,2020");
  Date d2("5/3/2020");
  Date d3("May 3 2020");
  print(std::cout, d1);
  print(std::cout, d2);
  print(std::cout, d3);

  return 0;
}
