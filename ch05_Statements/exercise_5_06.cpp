/*
 * 改写上一题的程序，使用条件运算符（参见4.7节，第134页）代替if else语句。
 */

#include <iostream>
#include <string>
#include <vector>

int main(void) {
    const std::vector<std::string> scores = {"F", "D", "C", "B", "A", "A++"};

    int grade;
    std::cout << "Enter a  grade: ";
    std::cin >> grade;

    std::string finalgrade = (grade < 60) ? scores[0] : scores[(grade - 50) / 10];
    finalgrade += (grade == 100 || grade < 60) ? "" : (grade  % 10 > 7) ? "+" : (grade % 10 < 3) ?  "-": "";
    std::cout << grade << " is " << finalgrade << std::endl;
    return 0;
}
