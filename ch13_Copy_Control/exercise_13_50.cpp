/*
 * 在你的String类的移动操作中添加打印语句，
 * 并重新运行13.6.1节（第473页）的练习13.48程序，
 * 它使用了一个vector，观察什么时候会避免拷贝。
 */

/*
 * 当重新分配空间时会避免调用拷贝构造函数，而使用移动构造函数。
 */


#include "include/String.h"
#include <vector>

int main(int argc, char const *argv[]) {
    std::vector<String> svec;
    for (int i = 0; i < 20; ++i) {
        std::cout << svec.capacity() << std::endl;
        svec.push_back("test");
    }
    return 0;
}
