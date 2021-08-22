/*
 * 修改5.5.1节（第171页）练习题的程序，使其找到的是重复单词必须以大写字母开头。
 */

#include <iostream>
#include <string>

int main(void) {
    std::string cur_word, pre_word;
    if (std::cin >> pre_word) {
        while ((std::cin >> cur_word) && (islower(cur_word[0]) || (cur_word != pre_word))) {
            std::cout << "Not the same." << std::endl;
            pre_word = cur_word;
        }
    }
    if (!cur_word.empty() && cur_word == pre_word) {
        std::cout << cur_word << " have the same." << std::endl;
    }
    return 0;
}
