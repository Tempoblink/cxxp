/*
 * 定义你自己版本的make_shared。
 */

#include <iostream>
#include <memory>
#include <string>
#include <utility>

template<typename T, typename... Args>
std::shared_ptr<T> make_shared(Args &&...args) {
    return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
}

int main(int argc, char const *argv[]) {
    std::shared_ptr<std::string> sp = make_shared<std::string>(10, 'c');
    std::cout << *sp << std::endl;
    return 0;
}
