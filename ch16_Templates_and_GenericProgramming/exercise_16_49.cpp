/*
 * 解释下面每个调用会发生什么。
 *
 * template <typename T> void f(T) { cout << "f(T)" << endl; }
 * template <typename T> void f(const T*) { cout << "f(const T*)" << endl; }
 * template <typename T> void g(T) { cout << "g(T)" << endl; }
 * template <typename T> void g(T*) { cout << "g(T*)" << endl; }
 * int i = 42, *p = &i;
 * const int ci = 0, *p2 = &ci;
 * g(42); g(p); g(ci); g(p2);
 * f(42); f(p); f(ci); f(p2);
 */

/*
 * g(42) -> template <typename T> void g(T) { cout << "g(T)" << endl; }
 * g(p)  -> template <typename T> void g(T*) { cout << "g(T*)" << endl; }
 * g(ci) -> template <typename T> void g(T) { cout << "g(T)" << endl; }
 * g(p2) -> template <typename T> void g(T*) { cout << "g(T*)" << endl; }
 *
 * f(42) -> template <typename T> void f(T) { cout << "f(T)" << endl; }
 * f(p)  -> template <typename T> void f(T) { cout << "f(T)" << endl; }
 * f(ci) -> template <typename T> void f(T) { cout << "f(T)" << endl; }
 * f(p2) -> template <typename T> void f(const T*) { cout << "f(const T*)" << endl; }
 */

#include <iostream>

template<typename T>
void f(T) { std::cout << "f(T)" << std::endl; }
template<typename T>
void f(const T *) { std::cout << "f(const T*)" << std::endl; }
template<typename T>
void g(T) { std::cout << "g(T)" << std::endl; }
template<typename T>
void g(T *) { std::cout << "g(T*)" << std::endl; }

int main(int argc, char const *argv[]) {
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;
    g(42);
    g(p);
    g(ci);
    g(p2);
    f(42);
    f(p);
    f(ci);
    f(p2);
}
