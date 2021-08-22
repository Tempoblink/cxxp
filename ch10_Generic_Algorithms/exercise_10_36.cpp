/*
 * 使用find在一个int的list中查找最后一个值为0的元素。
 */

#include <algorithm>
#include <iostream>
#include <list>

int main(int argc, char const *argv[]) {
    std::list<int> ilist{1, 2, 3, 4, 5, 0, 4, 5, 0, 9};
    auto wc = std::find(ilist.crbegin(), ilist.crend(), 0);
    if (wc != ilist.crend()) {
        int cout = 0;
        for (auto iter = ilist.cbegin(); iter != wc.base(); ++iter)
            ++cout;
        std::cout << "The last 0 is at "
                  << cout << std::endl;
    } else {
        std::cout << "Not found 0." << std::endl;
    }
    return 0;
}
