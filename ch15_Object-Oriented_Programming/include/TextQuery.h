#pragma once
#include <fstream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>
class QueryResult;

class TextQuery {
public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream &);
    QueryResult query(const std::string &) const;

private:
    std::shared_ptr<std::vector<std::string>> file;              //存放每行
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;//单词对应行的字典
};
