/*
 * 编写一段程序，定义两个字符数组并用字符串字面值初始化它们；接着再定义一个字符数组存放前两个数组连接后的结果。
 * 使用strcpy和strcat把前两个数组的内容拷贝到第三个数组中。
 */

#include <cstring>
#include <iostream>

int main(void) {
    char cs1[] = "Hello";
    char cs2[] = "World";
    char cs3[sizeof(cs1) + sizeof(cs2)];
    strcpy(cs3, cs1);
    strcat(cs3, cs2);
    std::cout << cs3 << std::endl;
    return 0;
}
