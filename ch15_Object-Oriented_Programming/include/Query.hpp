#pragma once

#include "Query_Action.h"

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
