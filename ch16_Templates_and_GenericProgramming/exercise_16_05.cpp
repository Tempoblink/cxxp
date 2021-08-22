/*
 * 为6.2.4节（第195页）中的print函数编写模板版本，
 * 它接受一个数组的引用，能处理任意大小、任意元素类型的数组。
 */

#include <iostream>

template<typename T, unsigned N>
void print(T (&arr)[N]) {
    for (const auto &elem : arr)
        std::cout << elem << std::endl;
}

int main(int argc, char const *argv[]) {
    int k[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(k);
    char c[] = {'a','b','c','d'};
    print(c);
    return 0;
}
