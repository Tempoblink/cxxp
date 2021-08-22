/*
 * 定义你自己版本的TextQuery和QueryResult类，并执行12.3.1节（第431页）中的runQueries函数。
 */


#include "include/QueryResult.h"
#include "include/TextQuery.h"

void RunQueries(std::ifstream &infile) {
    TextQuery tq(infile);
    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.query(s)) << std::endl;
    }
}

int main(int argc, char const *argv[]) {
    if (argc < 2) exit(1);
    std::ifstream file(argv[1], std::ifstream::in);
    RunQueries(file);
    return 0;
}
