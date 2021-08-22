#include "Blob.h"
#include "BlobPtr.h"

#include <list>

extern template class Blob<int>;
extern template class BlobPtr<int>;

int main(int argc, char const *argv[]) {
    Blob<int> ib{1, 2, 3, 4, 5, 6};
    Blob<int> ic{1, 2, 3, 4, 5, 6};

    BlobPtr<int> ibptr(ib);
    std::cout << (*ibptr) << std::endl;
    std::cout << std::boolalpha << (ib == ic) << std::endl;

    std::list<int> ilist{1, 2, 3, 4, 5, 6};
    Blob<int> ia(ilist.begin(), ilist.end());
    return 0;
}
