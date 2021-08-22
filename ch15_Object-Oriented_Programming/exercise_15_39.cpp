/*
 * 实现Query类和Query_base类，求图15.3（第565页）中表达式的值并打印相关信息，验证你的程序是否正确。
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
