/*
 * 假定iv是一个int的vector，下面的程序存在什么错误？你将如何修改？
 *
 * vector<int>::iterator iter = iv.begin(),
 *                       mid = iv.begin() + iv.size()/2;
 * while (iter != mid)
 *      if (*iter == some_val)
 *          iv.insert(iter, 2 * some_val);
 */

/*
 * 插入操作会使vector中所有的迭代器失效，如果继续使用将出现未定义的错误。
 * 没有递增iter，可能死循环。
 */

#include <iostream>
#include <vector>

int main(void) {
    int some_val = 3;
    std::vector<int> iv{1, 3, 2, 3, 5, 6, 7, 8, 9};
    std::vector<int>::size_type i = iv.size();
    std::vector<int>::iterator iter = iv.begin(), mid = iv.begin() + i;
    while (iter != mid) {
        if (*iter == some_val) {
            //迭代器指向新元素位置。
            iter = iv.insert(iter, 2 * some_val);
            //还原迭代器位置。
            ++iter;
            //丢失，找回。
            mid = iv.begin() + i;
        }
        ++iter;
    }

    std::cout << "iv = ";
    for (const auto &i : iv) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
