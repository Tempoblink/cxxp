/*
 * 使用一个map迭代器编写一个表达式，将一个值赋予一个元素。
 */

#include <iostream>
#include <map>
#include <string>

int main(int argc, char const *argv[]) {
    //key_type is a const type;
    std::map<std::string, int> s1;
    s1["Hi"] = 5;
    auto iter = s1.begin();
    std::cout << iter->first << std::endl;
    std::cout << iter->second << std::endl;
    iter->second = 1;
    std::cout << iter->first << std::endl;
    std::cout << iter->second << std::endl;
    return 0;
}
