
#include "TextQuery.h"
#include "QueryResult.h"
#include "StrVec.h"

TextQuery::TextQuery(std::ifstream &file) : data(new StrVec()) {
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
