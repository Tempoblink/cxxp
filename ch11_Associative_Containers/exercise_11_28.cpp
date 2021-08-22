/*
 * 对一个string到int的vector的map，
 * 定义并初始化一个变量来保存在其上调用find所返回的结果。
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>

int main(int argc, char const* argv[])
{
   std::map<std::string, std::vector<int>> smap;
   smap["Hi"].push_back(21);
   auto iter =  smap.find("Hi");
   std::cout << (*iter).first << std::endl;
   std::cout << (*iter).second.size() << std::endl;
   std::cout << *(*iter).second.begin() << std::endl;
  return 0;
}
