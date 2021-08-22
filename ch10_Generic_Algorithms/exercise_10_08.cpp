/*
 * 本节提到过，标准库算法不会改变它们所操作的容器的大小。为什么使用back_insertor不会使这一断言失效？
 */

/*
 * 当我们通过一个插入迭代器赋值时，一个与赋值号右侧值相等的元素被添加到容器中。
 *
 * 它们只操作迭代器，从而间接访问容器。
 * 能不能插入和删除元素，不在于算法，而在于传递给它们的迭代器是否具有这样的能力。
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

int main(int argc, char const *argv[]) {
    std::vector<int> avec;
    std::cout << avec.capacity() << std::endl;
    std::fill_n(std::back_inserter(avec), 10, 0);
    for (const auto &i : avec)
        std::cout << i << " ";
    std::cout << std::endl;
    std::cout << avec.capacity() << std::endl;
    return 0;
}
