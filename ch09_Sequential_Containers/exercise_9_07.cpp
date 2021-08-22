/*
 * 为了索引int的vector中的元素，应该使用什么类型？
 */

/*
 * 使用 std::vector<int>::size_type
 */

#include <iostream>
#include <vector>

int main(void) {
    std::vector<int> ivec(10, 0);
    std::vector<int>::size_type i = 2;
    std::cout << ivec[i] << std::endl;
    return 0;
}
