#include "Query.h"
#include <algorithm>
#include <iterator>

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
    NotQuery(const Query &q) : query(q) { std::cout << "NotQuery::NotQuery(const Query &)" << std::endl; }
    std::string rep() const {
        std::cout << "NotQuery::rep()" << std::endl;
        return "~(" + query.rep() + ")";
    }
    QueryResult eval(const TextQuery &) const;
    Query query;
};

class BinaryQuery : public Query_base {
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s) : lhs(l), rhs(r), opSym(s) { std::cout << "BinaryQuery::BinaryQuery(const Query &, const Query &)" << std::endl; }
    std::string rep() const {
        std::cout << "BinaryQuery::rep()" << std::endl;
        return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
    }
    Query lhs, rhs;
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
