#pragma once

#include <iostream>
#include <memory>
#include <set>
#include <string>
#include <vector>

//查询结果的对象类型
class QueryResult {
    friend std::ostream &operator<<(std::ostream &, const QueryResult &);

public:
    using line_no = std::vector<std::string>::size_type;
    QueryResult(const std::string &word, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<std::vector<std::string>> f) : sought(word), lines(p), file(f) {}
    std::set<line_no>::iterator begin() { return lines->begin(); }
    std::set<line_no>::iterator end() { return lines->end(); }
    std::shared_ptr<std::vector<std::string>> get_file() const { return file; };

private:
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;      //存放单词行号
    std::shared_ptr<std::vector<std::string>> file;//存在单词所在行
};

inline std::ostream &operator<<(std::ostream &os, const QueryResult &r) {
    os << r.sought << " occurs " << r.lines->size() << " time(s)" << std::endl;
    for (auto &mem : *r.lines) {
        size_t num = mem + 1;
        os << "(line " << num + 1 << ") "
           << *(r.file->begin() + num) << std::endl;
    }
    return os;
}
