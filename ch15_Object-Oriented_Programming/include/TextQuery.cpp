#include "TextQuery.h"
#include "QueryResult.h"

TextQuery::TextQuery(std::ifstream &f) : file(new std::vector<std::string>) {
    std::cout << "TextQuery::TextQuery(ifstream &)" << std::endl;
    std::string line;
    while (std::getline(f, line)) {
        file->push_back(line);
        int no = file->size() - 1;
        std::istringstream record(line);
        std::string word;
        //构建word 行号 字典
        while (record >> word) {
            auto &lines = wm[word];                //返回share_ptr
            if (!lines)                            //lines == nullptr
                lines.reset(new std::set<line_no>);//创建内存空间
            lines->insert(no);
        }
    }
}
QueryResult TextQuery::query(const std::string &word) const {
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);//未找到word
    auto loc = wm.find(word);
    if (loc == wm.end())
        return QueryResult(word, nodata, file);
    else
        return QueryResult(word, loc->second, file);
}
