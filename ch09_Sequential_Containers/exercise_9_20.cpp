/*
 * 编写程序，从一个list<int>拷贝元素到两个deque中。
 * 值为偶数的所有元素拷贝到一个deque中，而奇数值元素都拷贝到另一个deque中。
 */

#include <deque>
#include <iostream>
#include <list>

int main(void) {
    std::list<int> li{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::deque<int> odd_deq, even_deq;
    for (const auto &i : li) {
        if (i % 2 == 0)
            even_deq.push_back(i);
        else
            odd_deq.push_back(i);
    }

    std::cout << "even_deq = ";
    for (const auto &i : even_deq) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "odd_deq = ";
    for (const auto &i : odd_deq) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
