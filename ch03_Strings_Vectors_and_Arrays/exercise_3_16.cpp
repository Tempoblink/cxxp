/*
 * 编写一段程序，把练习3.13中vector对象的容量和具体内容输出出来。
 */

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


int main(void) {

    //a
    vector<int> v1;
    cout << "v1 has " << v1.size() << " sizes "
         << " There are: ";
    for (const auto &i : v1) {
        cout << i << " ";
    }
    cout << endl;

    //b
    vector<int> v2(10);
    cout << "v2 has " << v2.size() << " sizes "
         << "There are: ";
    for (const auto &i : v2) {
        cout << i << " ";
    }
    cout << endl;

    //c
    vector<int> v3(10, 42);
    cout << "v3 has " << v3.size() << " sizes "
         << "There are: ";
    for (const auto &i : v3) {
        cout << i << " ";
    }
    cout << endl;

    //d
    vector<int> v4{10};
    cout << "v4 has " << v4.size() << " sizes "
         << "There are: ";
    for (const auto &i : v4) {
        cout << i << " ";
    }
    cout << endl;

    //e
    vector<int> v5{10, 42};
    cout << "v5 has " << v5.size() << " sizes "
         << "There are: ";
    for (const auto &i : v5) {
        cout << i << " ";
    }
    cout << endl;

    //f
    vector<string> v6{10};
    cout << "v6 has " << v6.size() << " sizes "
         << "There are: ";
    for (const auto &i : v6) {
        cout << i << " ";
    }
    cout << endl;

    //g
    vector<string> v7{10, "hi"};
    cout << "v7 has " << v7.size() << " sizes"
         << "There are: ";
    for (const auto &i : v7) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
