/*
 * 编写你自己的DebugDelete版本。
 */

#include <iostream>
#include <memory>
#include <string>

class DebugDelete {
public:
    DebugDelete(std::ostream &s = std::cerr) : os(s) {}
    template<typename T>
    void operator()(T *p) {
        os << "deleting unique_ptr" << std::endl;
        delete p;
    }

private:
    std::ostream &os;
};

int main(int argc, char const *argv[]) {
    double *p = new double;
    DebugDelete Debug;
    Debug(p);
    int *q = new int;
    Debug(q);

    std::unique_ptr<int, DebugDelete> k(new int, DebugDelete());
    std::unique_ptr<std::string, DebugDelete> j(new std::string, DebugDelete());
    return 0;
}
