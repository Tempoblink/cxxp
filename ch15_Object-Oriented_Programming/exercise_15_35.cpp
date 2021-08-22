/*
 * 实现Query类和Query_base类，其中需要定义rep而无须定义eval。
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
