/*
 * 编写一个类似于PrintString的类，令其从istream中读取一行输入，
 * 然后返回一个表示我们所读内容的string，如果读取失败，返回空string。
 */

#include <iostream>
#include <string>

class PrintString {
public:
    PrintString(std::istream &input = std::cin) : is(input) {}
    std::string operator()() {
        std::getline(is, str);
        return str;
    }

private:
    std::istream &is;
    std::string str;
};

int main(int argc, char const *argv[]) {
    PrintString getLine;
    std::string test = getLine();
    std::cout << test << std::endl;
    return 0;
}
