#pragma onece
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

private:
    std::string word;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};
