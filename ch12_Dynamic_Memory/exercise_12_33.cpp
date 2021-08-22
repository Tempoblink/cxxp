/*
 * 在第15章中我们将扩展查询系统，在QueryResult类中将会需要一些额外的成员。
 * 添加名为begin和end的成员，返回一个迭代器，指向一个给定查询返回的行号的set中的位置。
 * 再添加一个名为get_file的成员，返回一个shared_ptr，指向QueryResult对象中的文件。
 */

#include <iostream>
#include <istream>
#include <memory>
#include <ostream>
#include <set>
#include <string>
#include <vector>

class QueryResult {
    using line_no = std::vector<std::string>::size_type;
    friend std::ostream &print(std::ostream &, const QueryResult &);

public:
    QueryResult(const std::string &s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<std::vector<std::string>> f)
        : word(s), lines(p), file(f) {}

    std::set<line_no>::iterator begin() { return lines->begin(); }
    std::set<line_no>::iterator end() { return lines->end(); }

    std::shared_ptr<std::vector<std::string>> get_file() const { return file; };

private:
    std::string word;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};


int main(int argc, char const *argv[]) {
    return 0;
}
