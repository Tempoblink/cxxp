/*
 * 假定v是一个vector<double>，
 * 那么调用accumulate(v.cbegin(), v.cend(), 0)有何错误（如果存在的话）？
 */

#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

int main(int argc, char const *argv[]) {
    std::vector<double> dvec{1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
    std::cout << "devc = " << std::accumulate(dvec.cbegin(), dvec.cend(), 0.0)
              << std::endl;
    return 0;
}
