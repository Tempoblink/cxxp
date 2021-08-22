
/*
 * 下面的代码调用了第413页中定义的process函数，解释此调用是否正确。如果不正确，应如何修改？
 *
 * shared_ptr<int> p(new int(42));
 * process(shared_ptr<int>(p));
 */

/*
 * 正确。p是一个智能指针，其指向的动态内存会被正确释放。
 * 向函数传递的是指针拷贝。
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

void process2(std::shared_ptr<int> &ptr) {
    std::cout << "In process2:\t "
              << reinterpret_cast<std::int_fast64_t>(&ptr)
              << " "
              << reinterpret_cast<std::int_fast64_t>(&(*ptr))
              << std::endl;
}

int main(int argc, char const *argv[]) {
    std::shared_ptr<int> p(new int(42));
    std::cout << "In main:\t "
              << reinterpret_cast<std::int_fast64_t>(&p)
              << " "
              << reinterpret_cast<std::int_fast64_t>(&(*p))
              << std::endl;
    process1(std::shared_ptr<int>(p));
    process2(p);
    return 0;
}
