/*
 * 编写你自己版本的StrVec，
 * 包括自己版本的reserve、capacity（参见9.4节，第318页）和resize（参见9.3.5节，第314页）。
 */

#include "include/StrVec.h"
#include <iostream>
#include <memory>
#include <string>


int main(int argc, char const *argv[]) {
    StrVec svec;
    svec.push_back("Hello");
    svec.push_back("World");
    svec.push_back("Hey");
    std::cout << "svec.capacity = " << svec.capacity() << std::endl;
    std::cout << "svec.size = " << svec.size() << std::endl;
    auto ret = svec.begin();
    while (ret != svec.end()) {
        std::cout << *ret << std::endl;
        ++ret;
    }

    svec.resize(4);
    std::cout << "svec.capacity = " << svec.capacity() << std::endl;
    std::cout << "svec.size = " << svec.size() << std::endl;
    ret = svec.begin();
    while (ret != svec.end()) {
        std::cout << *ret << std::endl;
        ++ret;
    }

    svec.reserve(5);
    std::cout << "svec.capacity = " << svec.capacity() << std::endl;
    std::cout << "svec.size = " << svec.size() << std::endl;
    ret = svec.begin();
    while (ret != svec.end()) {
        std::cout << *ret << std::endl;
        ++ret;
    }


    return 0;
}
