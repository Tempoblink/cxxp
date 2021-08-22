/*
 * 重写TextQuery和QueryResult类，用StrBlob代替vector<string>保存输入文件。
 */


#include "include/StrBlob.h"
#include "include/StrBlobPtr.h"
#include <fstream>
#include <iterator>
#include <map>
#include <iostream>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class QueryResult;

using line_no = std::vector<std::string>::size_type;

class TextQuery {

public:
    TextQuery(std::ifstream &);
    QueryResult query(const std::string &) const;

private:
    //每行数据保存
    std::shared_ptr<StrBlob> data;
    //单词 对应的 行号
    std::map<std::string, std::shared_ptr<std::set<line_no>>> smap;
};

class QueryResult {
    friend std::ostream &print(std::ostream &, const QueryResult &);

public:
    QueryResult(const std::string &s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<StrBlob> f)
        : word(s), lines(p), file(f) {}

private:
    std::string word;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<StrBlob> file;
};

TextQuery::TextQuery(std::ifstream &file) : data(new StrBlob) {
    std::string line;
    while (std::getline(file, line)) {
        data->push_back(line);
        line_no n = data->size() - 1;
        std::string word;
        std::istringstream record(line);
        while (record >> word) {
            auto &ret = smap[word];
            if (!ret)
                ret.reset(new std::set<line_no>);
            ret->emplace(n);
        }
    }
}

QueryResult TextQuery::query(const std::string &word) const {
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
    auto loc = smap.find(word);
    if (loc == smap.end())
        return QueryResult(word, nodata, data);
    else
        return QueryResult(word, loc->second, data);
}

std::ostream &print(std::ostream &os, const QueryResult &result) {
    os << result.word << " occurs " << result.lines->size() << " "
       << (result.lines->size() > 1 ? "times" : "time") << std::endl;

    for (auto num : *result.lines) {
        os << "\t(line " << num + 1 << ") ";
        auto ret = result.file->begin();
        while (num) {
            ret = ret.incr();
            --num;
        }
        os << ret.deref() << std::endl;
    }
    return os;
}

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
