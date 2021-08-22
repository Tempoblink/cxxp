#include "QueryResult.h"
#include "StrVec.h"

std::ostream &print(std::ostream &os, const QueryResult &result) {
    os << result.word << " occurs " << result.lines->size() << " "
       << (result.lines->size() > 1 ? "times" : "time") << std::endl;

    for (auto num : *result.lines) {
        os << "\t(line " << num + 1 << ") "
           << *(result.file->begin() + num) << std::endl;
    }
    return os;
}
