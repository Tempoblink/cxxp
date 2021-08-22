/*
 * 编写一个类令其检查两个值是否相等。
 * 使用该对象及标准库算法编写程序，令其替换某个序列中具有给定值的所有实例。
 */

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <vector>

class Equal {
public:
    Equal(const int &i) : a(i) {}
    bool operator()(const int &test) {
        return a == test;
    }

private:
    int a;
};

int main(int argc, char const *argv[]) {
    std::system("clear");
    std::vector<int> ivec{1, 1, 1, 2, 2, 2, 3, 3, 3};
    std::for_each(ivec.begin(), ivec.end(), [](const int &i) { std::cout << i << " "; });
    std::cout << std::endl;
    sleep(1);
    std::system("clear");
    std::replace_if(ivec.begin(), ivec.end(), Equal(2), 1);
    std::for_each(ivec.begin(), ivec.end(), [](const int &i) { std::cout << i << " "; });
    std::cout << std::endl;
    sleep(1);
    std::system("clear");
    std::replace_if(ivec.begin(), ivec.end(), Equal(3), 1);
    std::for_each(ivec.begin(), ivec.end(), [](const int &i) { std::cout << i << " "; });
    std::cout << std::endl;

    return 0;
}
