/*
 * 编写一个函数声明，使其返回数组的引用并且该数组包含10个string对象。
 * 不要使用尾置返回类型、decltype或者类型别名。
 */

#include <iostream>
#include <string>

std::string (&func(std::string (&str)[10]))[10] {
    for (auto &var : str) {
        var += "+";
    }
    return str;
}


int main(void) {
    std::string str[10] = {
            "Apple",
            "Banana",
            "Car",
            "Doctor",
            "Enter",
            "Fox",
            "Good",
            "Hand",
            "Internet",
            "Job"};

    for (const auto &var : func(str)) {
        std::cout << var << " ";
    }
    std::cout << std::endl;
    return 0;
}
