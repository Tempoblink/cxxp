/*
 * 编写你自己版本的shared_ptr和unique_ptr。
 */

#include "include/Shared_Ptr.h"
#include "include/Unique_Ptr.h"

int main(int argc, char const *argv[]) {
    int *p = new int(42);
    const Shared_Ptr<int> sp(p);
    Shared_Ptr<int> sp2(sp);
    int *q = new int(43);
    Shared_Ptr<int> sq(q);
    std::cout << *sp.get() << std::endl;
    std::cout << std::boolalpha << sp.unique() << std::endl;
    std::cout << sp.use_count() << std::endl;
    sp2.swap(sq);
    std::cout << *sp2 << std::endl;
    std::cout << *sq << std::endl;
    
    return 0;
}
