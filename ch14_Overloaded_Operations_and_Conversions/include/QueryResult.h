#pragma onece
#include <iostream>
#include <istream>
#include <memory>
#include <ostream>
#include <set>
#include <string>
#include <vector>

class StrVec;
class QueryResult {
    using line_no = size_t;
    friend std::ostream &print(std::ostream &, const QueryResult &);

public:
    QueryResult(const std::string &s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<StrVec> f)
        : word(s), lines(p), file(f) {}

private:
    std::string word;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<StrVec> file;
};
