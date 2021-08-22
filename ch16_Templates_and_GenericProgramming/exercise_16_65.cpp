/*
 * 在16.3节（第617页）中我们定义了两个重载的debug_rep版本，
 * 一个接受const char*参数，另一个接受char*参数。
 * 将这两个函数重写为特例化版本。
 */

#include <iostream>
#include <sstream>
#include <string>

template<typename T>
std::string debug_rep(const T &t) {
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

template<typename T>
std::string debug_rep(T *p) {
    std::ostringstream ret;
    ret << "pointer: " << p;
    if (p)
        ret << " " << debug_rep(*p);
    else
        ret << " null pointer";
    return ret.str();
}

template<>
std::string debug_rep(const std::string &s) {
  return '"' + s + '"';
}

template<>
std::string debug_rep(char *p) {
    return debug_rep(std::string(p));
}


template<>
std::string debug_rep(const char *p) {
    return debug_rep(std::string(p));
}

int main(int argc, char const *argv[]) {
    std::cout << debug_rep("Hello") << std::endl;
    return 0;
}
