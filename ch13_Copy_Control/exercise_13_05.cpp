/*
 * 给定下面的类框架，编写一个拷贝构造函数，拷贝所有成员。
 * 你的构造函数应该动态分配一个新的string（参见12.1.2节，第407页），
 * 并将对象拷贝到ps指向的位置，而不是ps本身的位置。
 *
 * class HasPtr {
 *  public:
 *    HasPtr(const std::string &s = std::string()) :
 *	    ps(new std::string(s)), i(0) {}
 *  private:
 *      std::string *ps;
 *	    int i;
 * };
*/


#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &);

private:
    std::string *ps;
    int i;
};

HasPtr::HasPtr(const HasPtr &h) : ps(new std::string(*h.ps)), i(h.i) {}

int main(int argc, char const *argv[]) {
    return 0;
}
