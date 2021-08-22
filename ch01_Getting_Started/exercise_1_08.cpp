/*
 * 指出下列哪些输出语句是合法的（如果有的话）
 */

// std::cout << "/*";
// std::cout << "*/";
// std::cout << /* "*/" */;
// std::cout << /* "*/" /* "/*" */;

/*
 * 只有第三个不合法，应在最后加"
 */

//结果： /**/ */ /*

#include <iostream>

int main(void) {
    std::cout << "/*";
    std::cout << "*/";
    std::cout << /* "*/ " */";
    std::cout << /* "*/ " /* " /*" */;
    return 0;
}
