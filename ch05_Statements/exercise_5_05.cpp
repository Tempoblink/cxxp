/*
 * 写一段自己的程序，使用if else语句实现把数字成绩转换成字母成绩的要求。
 */

#include <iostream>
#include <string>
#include <vector>

int main(void) {
    const std::vector<std::string> scores = {"F", "D", "C", "B", "A", "A++"};

    int grade;
    std::cout << "Enter a  grade: ";
    std::cin >> grade;

    std::string finalgrade;
    if (grade < 60) {
        finalgrade = scores[0];
    } else {
        finalgrade = scores[(grade - 50) / 10];
        if (grade != 100)
            if (grade % 10 > 7)
                finalgrade += '+';
            else if (grade % 10 < 3)
                finalgrade += '-';
    }
    std::cout << grade << " is " << finalgrade << std::endl;
    return 0;
}
