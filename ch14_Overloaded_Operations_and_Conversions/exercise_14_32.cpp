/*
 * 定义一个类令其有指向StrBlobPtr对象的指针，为这个类定义重载的箭头运算符。
 */

#include "include/StrBlob.h"
#include "include/StrBlobPtr.h"
#include <memory>


class PtrtoStrBlobPtr {
public:
    PtrtoStrBlobPtr(StrBlobPtr *m) : p(m) {}

    StrBlobPtr &operator->() {
        return *p;
    }

private:
    StrBlobPtr *p;
};

int main(int argc, char const *argv[]) {
    StrBlob b{"Hello", "Hi", "Hey"};
    StrBlobPtr p(b);
    PtrtoStrBlobPtr pt(&p);
    // pt -> StrBlobPtr -> string 
    std::cout << *(pt->begin()) << std::endl;
    return 0;
}
