/*
 * 如果在派生类中含有shared_ptr<Query_base>类型的成员而非Query类型的成员，则你的类需要做出怎样的改变？
 */

#include "include/QueryResult.h"
#include "include/TextQuery.h"
#include <algorithm>
#include <iterator>
#include <memory>

class Query;
class Query_base {
    friend class Query;
    friend class NotQuery;
    friend class BinaryQuery;
    friend class AndQuery;
    friend class OrQuery;

protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;

private:
    virtual QueryResult eval(const TextQuery &) const = 0;
    virtual std::string rep() const = 0;
};

class Query {
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);

    friend class NotQuery;
    friend class BinaryQuery;
    friend class AndQuery;
    friend class OrQuery;

public:
    Query(const std::string &);
    QueryResult eval(const TextQuery &t) const { return q->eval(t); }
    std::string rep() const {
        std::cout << "Query::rep()" << std::endl;
        return q->rep();
    }

private:
    // 连接内部实现的接口
    Query(std::shared_ptr<Query_base> query) : q(query) { std::cout << "Query(shared_ptr<Query_base>)" << std::endl; }
    std::shared_ptr<Query_base> q;
};

class WordQuery : public Query_base {
    friend class Query;
    WordQuery(const std::string &word) : query_word(word) { std::cout << "WordQuery::WordQuery(const string &)" << std::endl; }
    QueryResult eval(const TextQuery &t) const {
        return t.query(query_word);
    }
    std::string rep() const {
        std::cout << "WordQuery::rep()" << std::endl;
        return query_word;
    }
    std::string query_word;
};

class NotQuery : public Query_base {
    friend Query operator~(const Query &);
    NotQuery(const Query &q) : query(q.q) { std::cout << "NotQuery::NotQuery(const Query &)" << std::endl; }
    std::string rep() const {
        std::cout << "NotQuery::rep()" << std::endl;
        return "~(" + query->rep() + ")";
    }
    QueryResult eval(const TextQuery &) const;
    std::shared_ptr<Query_base> query;
};

class BinaryQuery : public Query_base {
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s) : lhs(l.q), rhs(r.q), opSym(s) { std::cout << "BinaryQuery::BinaryQuery(const Query &, const Query &)" << std::endl; }
    std::string rep() const {
        std::cout << "BinaryQuery::rep()" << std::endl;
        return "(" + lhs->rep() + " " + opSym + " " + rhs->rep() + ")";
    }
    std::shared_ptr<Query_base> lhs, rhs;
    std::string opSym;
};

class AndQuery : public BinaryQuery {
    friend Query operator&(const Query &, const Query &);
    AndQuery(const Query &l, const Query &r) : BinaryQuery(l, r, "&") { std::cout << "AndQuery(const Query &, const Query &)" << std::endl; }
    QueryResult eval(const TextQuery &) const;
};

class OrQuery : public BinaryQuery {
    friend Query operator|(const Query &, const Query &);
    OrQuery(const Query &l, const Query &r) : BinaryQuery(l, r, "|") { std::cout << "OrQuery(const Query &, const Query &)" << std::endl; }
    QueryResult eval(const TextQuery &) const;
};

QueryResult AndQuery::eval(const TextQuery &text) const {
    //左侧查询结果 和右侧查询结果
    auto left = lhs->eval(text), right = rhs->eval(text);
    //保存 两者关系后的行号结果
    auto ret_lines = std::make_shared<std::set<line_no>>();
    //相同插入
    std::set_intersection(left.begin(), left.end(), right.begin(), right.end(), std::inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult OrQuery::eval(const TextQuery &text) const {
    auto left = lhs->eval(text), right = rhs->eval(text);
    auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());
    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult NotQuery::eval(const TextQuery &text) const {
    auto result = query->eval(text);
    auto ret_lines = std::make_shared<std::set<line_no>>();
    auto beg = result.begin(), end = result.end();
    auto sz = result.get_file()->size();
    for (size_t n = 0; n < sz; ++n) {
        //beg 不等于n 插入 ,beg到尾后，剩余的行号插入
        if (beg == end || *beg != n)
            ret_lines->insert(n);
        else if (beg != end)
            ++beg;
    }
    return QueryResult(rep(), ret_lines, result.get_file());
}

inline Query::Query(const std::string &word) : q(new WordQuery(word)) {
  std::cout << "Query::Query(const string &)" << std::endl;
}

inline std::ostream &operator<<(std::ostream &os, const Query &q) {
    return os << q.rep();
}

inline Query operator&(const Query &lhs, const Query &rhs) {
    //Query(std::shared_ptr<Query_base>) 初始化
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

inline Query operator|(const Query &lhs, const Query &rhs) {
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

inline Query operator~(const Query &s) {
    return std::shared_ptr<Query_base>(new NotQuery(s));
}

int main(int argc, char const *argv[]) {
    if (argc < 2) exit(1);
    std::ifstream file(argv[1]);
    if (!file) exit(1);

    TextQuery text(file);

    Query q = Query("fiery") & Query("bird") | Query("wind");
    std::cout << q.rep() << std::endl;
    auto result = q.eval(text);
    std::cout << result << std::endl;
    return 0;
}
