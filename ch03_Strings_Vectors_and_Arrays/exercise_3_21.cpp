/*
 * 请使用迭代器重做3.3.3节的第一个练习。
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
    for (auto it = v1.begin(); it != v1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    //b
    vector<int> v2(10);
    cout << "v2 has " << v2.size() << " sizes "
         << "There are: ";
    for (auto it = v2.begin(); it != v2.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    //c
    vector<int> v3(10, 42);
    cout << "v3 has " << v3.size() << " sizes "
         << "There are: ";
    for (auto it = v3.begin(); it != v3.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    //d
    vector<int> v4{10};
    cout << "v4 has " << v4.size() << " sizes "
         << "There are: ";
    for (auto it= v4.begin(); it != v4.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    //e
    vector<int> v5{10, 42};
    cout << "v5 has " << v5.size() << " sizes "
         << "There are: ";
    for (auto it = v5.begin(); it != v5.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    //f
    vector<string> v6{10};
    cout << "v6 has " << v6.size() << " sizes "
         << "There are: ";
    for (auto it = v6.begin(); it != v6.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    //g
    vector<string> v7{10, "hi"};
    cout << "v7 has " << v7.size() << " sizes"
         << "There are: ";
    for (auto it = v7.begin(); it != v7.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
