/*
 * 下面程序有何错误？你应该如何修改它？
 *
 * list<int> lst1;
 * list<int>::iterator iter1 = lst1.begin(),
 *                     iter2 = lst1.end();
 * while (iter1 < iter2) ...
 */

#include <iostream>
#include <list>

using std::list;

int main(void) {
    list<int> lst1;
    list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
    while (iter1 != iter2)
        ;
    return 0;
}
