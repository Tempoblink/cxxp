/*
 * 编写函数，接受一个容器的引用，打印容器中的元素。
 * 使用容器的size_type和size成员来控制打印元素的循环。
 */

#include <iostream>
#include <vector>

template<typename container>
void print_container(const container &c) {
    for (typename container::size_type i = 0; i < c.size(); ++i) {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[]) {
    std::vector<int> ivec{1, 2, 3, 4, 5};
    print_container(ivec);
    return 0;
}
