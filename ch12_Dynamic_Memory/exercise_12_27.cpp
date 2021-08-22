/*
 * TextQuery和QueryResult类只使用了我们已介绍过的语言和标准库特性。
 * 不要提前看后续章节内容，只用已经学到的知识编写你自己的版本。
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
