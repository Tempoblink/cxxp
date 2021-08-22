/*
 * 当我们拷贝一个StrBlob时，会发生什么？拷贝一个StrBlobPtr呢？
 */

/*
 * 拷贝StrBlob，会拷贝shared_ptr，从而使其引用计数递增。
 * 拷贝StrBlobPtr，不会增加其引用计数
 */

#include <iostream>
#include <memory>

int main(int argc, char const *argv[]) {
    std::shared_ptr<int> i(new int(42));
    std::weak_ptr<int> p, q;

    std::cout << "*i = " << *i << std::endl;
    p = i;
    std::cout << "p.use_count = " << p.use_count() << std::endl;
    q = p.lock();
    std::cout << "q.use_count = " << q.use_count() << std::endl;

    i.reset();
    std::cout << "p.use_count = " << p.use_count() << std::endl;
    std::cout << "q.use_count = " << q.use_count() << std::endl;

    i.reset(new int(3));
    p = i;
    q = p.lock();
    std::cout << "*i = " << *i << std::endl;
    std::cout << "p.use_count = " << p.use_count() << std::endl;
    std::cout << "q.use_count = " << q.use_count() << std::endl;
    
    q = p.lock();
    std::cout << "q.use_count = " << q.use_count() << std::endl;

    return 0;
}
