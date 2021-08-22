/*
 * 编写一段程序读入两个字符串，比较其是否相等并输出结果。如果不想等，输出较大的那个字符串。
 * 改写上述程序，比较输入的两个字符串是否等长，如果不等长，输出长度较大的那个字符串。
 */

#include <iostream>
#include <string>

int main(void) {
    std::string word1, word2;
    std::cout << "Enter two words: ";
    std::cin >> word1 >> word2;

    //判断是否相等
    if (word1 == word2) {
        std::cout << "There are the same!" << std::endl;
    } else if (word1 > word2) {
        std::cout << "The larger word is: " << word1 << std::endl;
    } else {
        std::cout << "The larger word is: " << word2 << std::endl;
    }

    //判断长度相等
    if (word1.size() == word2.size()) {
        std::cout << "There are some length." << std::endl;
    } else if (word1.size() > word2.size()) {
        std::cout << "The longest word is: " << word1 << std::endl;
    } else {
        std::cout << "The longest word is: " << word2 << std::endl;
    }
    return 0;
}
