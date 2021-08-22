/*
 * 假定c是一个string的multiset，v是一个string的vector，
 * 解释下面的调用。指出每个调用是否合法。
 */

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    std::vector<std::string> v{"h", "a", "u"};
    std::multiset<std::string> c;
    copy(v.begin(), v.end(), inserter(c, c.end()));  //true
    // copy(v.begin(), v.end(), back_inserter(c));      //no push_back(),set is a const string.
    copy(c.begin(), c.end(), inserter(v, v.end()));  //true
    copy(c.begin(), c.end(), back_inserter(v));      //true

    return 0;
}
