/*
 * 为了读取string的list中的元素，应该使用什么类型？如果写入list，又该使用什么类型？
 */

/*
 * 读取： std::list<std::string>::const_iterator
 * 写入： std::list<std::string>::iterator
 */

#include <iostream>
#include <list>

int main(void)
{
  std::list<std::string>::iterator it_write;
  std::list<std::string>::const_iterator it_read;
  return 0;
}
