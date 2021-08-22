#include "Query_Action.h"

// AndQuery

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
