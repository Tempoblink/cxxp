#include "Query_Base.h"

class Query {

    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);

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
