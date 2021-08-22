/*
 * 在你的TextQuery和QueryResult类（参加12.3节，第431页）中用你的StrVec类代替vector，
 * 以此来测试你的StrVec类。
 */

#include "include/QueryResult.h"
#include "include/TextQuery.h"
#include <fstream>


int main(int argc, char const *argv[]) {
    if (argc < 2) exit(1);
    std::ifstream file(argv[1], std::fstream::in);
    if (!file) exit(1);

    TextQuery t1(file);
    QueryResult r1 = t1.query("and");
    print(std::cout, r1);
    return 0;
}
