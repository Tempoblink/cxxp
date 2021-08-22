/*
 * 编写程序，接受三个参数：一个输入文件和两个输出文件的文件名。
 * 输入文件保存的应该是整数。使用istream_iterator读取输入文件。
 * 使用ostream_iterator将奇数写入第一个输出文件，每个值之后都跟一个空格。
 * 将偶数写入第二个输出文件，每个值都独占一行。
 */

#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>

int main(int argc, char const *argv[]) {
    if (argc < 3) exit(1);
    std::fstream in_file(argv[1], std::fstream::in);
    if (!in_file) exit(1);

    // 截断
    std::fstream odd_file(argv[2], std::fstream::out);
    std::fstream even_file(argv[3], std::fstream::out);

    std::istream_iterator<int> read(in_file), read_end;
    while (read != read_end) {
        if (*read % 2)
            odd_file << *read++ << " ";
        else
            even_file << *read++ << std::endl;
    }
    odd_file << std::endl;
    return 0;
}
