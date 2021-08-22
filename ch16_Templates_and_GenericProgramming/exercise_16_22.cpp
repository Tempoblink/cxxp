/*
 * 修改12.3节（第430页）中你的TextQuery程序，
 * 令shared_ptr成员使用DebugDelete作为它们的删除器（参加12.1.4节，第415页）。
 */

#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class DebugDelete {
public:
    DebugDelete(std::ostream &s = std::cerr) : os(s) {}
    template<typename T>
    void operator()(T *q) {
        std::cerr << "delete share_ptr" << std::endl;
        delete q;
    }

private:
    std::ostream &os;
};

class QueryResult;

class TextQuery {
public:
    typedef std::vector<std::string>::size_type line_no;
    TextQuery(std::ifstream &);
    QueryResult query(const std::string &) const;

private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult {
    friend std::ostream &operator<<(std::ostream &, const QueryResult &);

public:
    typedef TextQuery::line_no line_no;
    QueryResult(const std::string &s, std::shared_ptr<std::set<line_no>> l, std::shared_ptr<std::vector<std::string>> f) : sought(s), lines(l), file(f) {}

private:
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};

TextQuery::TextQuery(std::ifstream &f) : file(new std::vector<std::string>, DebugDelete()) {
    std::string text;
    while (getline(f, text)) {
        file->push_back(text);
        int n = file->size() - 1;
        std::istringstream line(text);
        std::string word;
        while (line >> word) {
            auto &lines = wm[word];
            if (!lines)
                lines.reset(new std::set<line_no>);
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const std::string &sought) const {
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>(), DebugDelete());
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

std::ostream &operator<<(std::ostream &os, const QueryResult &q) {
    os << q.sought << " occurs " << q.lines->size() << " "
       << (q.lines->size() > 1 ? "times" : "time") << std::endl;
    for (auto num : *q.lines)
        os << "\t(line " << num + 1 << ")"
           << *(q.file->begin() + num) << std::endl;
    return os;
}

int main(int argc, char const *argv[]) {
    if (argc < 2) exit(1);
    std::ifstream file(argv[1]);
    if (!file) exit(1);
    TextQuery t(file);
    auto result = t.query("and");
    std::cout << result << std::endl;
    return 0;
}
