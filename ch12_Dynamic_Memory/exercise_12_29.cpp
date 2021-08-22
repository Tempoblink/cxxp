/*
 * 我们曾用do while循环来编写管理用户交互的循环（参见5.4.4节，第169页）。
 * 用do while重写本节程序，解释你倾向于哪个版本，为什么？
 */

#include "include/QueryResult.h"
#include "include/TextQuery.h"

void RunQueries(std::ifstream &infile) {
    TextQuery tq(infile);
    do {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.query(s)) << std::endl;
    } while (true);
}

int main(int argc, char const *argv[]) {
    if (argc < 2) exit(1);
    std::ifstream file(argv[1], std::ifstream::in);
    RunQueries(file);
    return 0;
}
