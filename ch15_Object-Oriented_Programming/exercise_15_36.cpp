/*
 * 在构造函数和rep成员中添加打印语句，允许你的代码以检查你对本节第一个练习中(a)、(b)两小题的回答是否正确。
 */

#include "include/Query.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {
    if (argc < 2) exit(1);
    std::ifstream file(argv[1]);
    if (!file) exit(1);

    TextQuery text(file);

    Query q = Query("fiery") & Query("bird") | Query("wind");
    std::cout << q.rep() << std::endl;
    auto result = q.eval(text);
    std::cout << result << std::endl;
    return 0;
}
