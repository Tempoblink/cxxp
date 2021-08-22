/*
 * 可以用什么类型来对一个map进行下标操作？
 * 下标运算符返回的类型是什么？
 * 请给出一个具体例子——即定义一个map，
 * 然后写出一个可以用来对map进行下标操作的类型以及下标运算符将会返回的类型。
 */

/*
 * 只要这个类型可以作为map的关键字，就可以将其作为下标。
 *
 * 当对一个map进行下标，得到的是一个mapped_type对象
 * 当解引用一个map迭代器时，得到的是一个value_type对象
 *
 */

#include <iostream>
#include <map>
#include <string>


int main(int argc, char const *argv[]) {
    std::map<std::string, int> imap;
    ++imap["Hi"];
    std::cout << imap["Hi"] << std::endl;
    return 0;
}
