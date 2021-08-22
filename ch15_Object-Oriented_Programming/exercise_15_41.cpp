/*
 * 重新实现你的类，这次使用指向Query_base的内置指针而非shared_ptr。
 * 请注意，做出上述改动后你的类将不能再使用合成的拷贝控制成员。
 */

#include "include/QueryResult.h"
#include "include/TextQuery.h"
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <memory>

class Query;
class Query_base {
    friend class Query;

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

public:
    Query(const std::string &);
    QueryResult eval(const TextQuery &t) const { return q->eval(t); }
    std::string rep() const {
        return q->rep();
    }
    Query(const Query &rhs) : q(rhs.q), used(rhs.used) { ++*used; }
    Query &operator=(const Query &rhs) {
        ++*rhs.used;
        if (--*used == 0) {
            delete q;
            delete used;
        }
        q = rhs.q;
        used = rhs.used;
        return *this;
    }
    ~Query() {
        if (--*used == 0) {
            delete q;
            delete used;
        }
    }

private:
    // 连接内部实现的接口
    Query(Query_base *query) : q(query), used(new std::size_t(1)) {}
    std::size_t *used;
    Query_base *q;
};

class WordQuery : public Query_base {
    friend class Query;
    WordQuery(const std::string &word) : query_word(word) {}
    QueryResult eval(const TextQuery &t) const {
        return t.query(query_word);
    }
    std::string rep() const {
        return query_word;
    }
    std::string query_word;
};

class NotQuery : public Query_base {
    friend Query operator~(const Query &);
    NotQuery(const Query &q) : query(q) {}
    std::string rep() const {
        return "~(" + query.rep() + ")";
    }
    QueryResult eval(const TextQuery &) const;
    Query query;
};

class BinaryQuery : public Query_base {
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s) : lhs(l), rhs(r), opSym(s) {}
    std::string rep() const {
        return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
    }
    Query lhs, rhs;
    std::string opSym;
};

class AndQuery : public BinaryQuery {
    friend Query operator&(const Query &, const Query &);
    AndQuery(const Query &l, const Query &r) : BinaryQuery(l, r, "&") {}
    QueryResult eval(const TextQuery &) const;
};

class OrQuery : public BinaryQuery {
    friend Query operator|(const Query &, const Query &);
    OrQuery(const Query &l, const Query &r) : BinaryQuery(l, r, "|") {}
    QueryResult eval(const TextQuery &) const;
};

QueryResult AndQuery::eval(const TextQuery &text) const {
    //左侧查询结果 和右侧查询结果
    auto left = lhs.eval(text), right = rhs.eval(text);
    //保存 两者关系后的行号结果
    auto ret_lines = std::make_shared<std::set<line_no>>();
    //相同插入
    std::set_intersection(left.begin(), left.end(), right.begin(), right.end(), std::inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult OrQuery::eval(const TextQuery &text) const {
    auto left = lhs.eval(text), right = rhs.eval(text);
    auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());
    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult NotQuery::eval(const TextQuery &text) const {
    auto result = query.eval(text);
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

inline Query::Query(const std::string &word) : q(new WordQuery(word)), used(new std::size_t(1)) {}

inline std::ostream &operator<<(std::ostream &os, const Query &q) {
    return os << q.rep();
}

inline Query operator&(const Query &lhs, const Query &rhs) {
    //Query(std::shared_ptr<Query_base>) 初始化
    return (new AndQuery(lhs, rhs));
}

inline Query operator|(const Query &lhs, const Query &rhs) {
    return (new OrQuery(lhs, rhs));
}

inline Query operator~(const Query &s) {
    return (new NotQuery(s));
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
