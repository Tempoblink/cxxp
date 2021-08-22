#pragma once

#include <fstream>
#include <iterator>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class QueryResult;

class TextQuery {
    using line_no = std::vector<std::string>::size_type;

public:
    TextQuery(std::ifstream &);
    QueryResult query(const std::string &) const;

private:
    //每行数据保存
    std::shared_ptr<std::vector<std::string>> data;
    //单词 对应的 行号
    std::map<std::string, std::shared_ptr<std::set<line_no>>> smap;
};
