/*
 * p和q的定义如下，对于接下来的对process的每个调用，如果合法，解释它做了什么，如果不合法，解释错误的原因：
 *
 * auto p = new int();
 * auto sp = make_shared<int>();
 *
 * (a) process(sp);
 * (b) process(new int());
 * (c) process(p);
 * (d) process(shared_ptr<int>(p));
 */

/*
 * (a) 合法，sp拷贝复制给process。
 * (b) 不合法，无法隐式初始化一个shared指针。
 * (c) 不合法，无法隐式初始化一个shared指针。
 * (d) 合法，将一个临时p的share指针拷贝复制给process。
 */

#include <algorithm>
#include <iostream>
#include <memory>

void process1(std::shared_ptr<int> ptr) {
    std::cout << "In process1:\t "
              << reinterpret_cast<std::int_fast64_t>(&ptr)
              << " "
              << reinterpret_cast<std::int_fast64_t>(&(*ptr))
              << std::endl;
}

int main(int argc, char const *argv[]) {
    std::shared_ptr<int> p(new int(42));
    std::cout << "In first main:\t "
              << reinterpret_cast<std::int_fast64_t>(&p)
              << " "
              << reinterpret_cast<std::int_fast64_t>(&(*p))
              << std::endl;
    process1(std::shared_ptr<int>(p));
    std::cout << "In second main:\t "
              << reinterpret_cast<std::int_fast64_t>(&p)
              << " "
              << reinterpret_cast<std::int_fast64_t>(&(*p))
              << std::endl;

    std::cout << "p = " << *p << std::endl;
    return 0;
}
