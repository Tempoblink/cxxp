/*
 * 解释下面代码的含义，说明其中的Type和initVal分别使用了哪个定义。
 * 如果代码存在错误，尝试修改它。
 */

#include <iostream>
#include <string>

typedef std::string Type;

Type initVal();
class Exercise {
public:
    typedef double Type;
    Type setVal(Type);
    Type initVal();

private:
    int val;
};

/*
* Type Exercise::setVal(Type parm) {
*   val = parm + initVal();
*   return val;
* }
*/

/*
 * 返回类型Type是string，类没有这个声明，是错误的。
 * 参数Type是double，没问题
 * initVal缺少实现，有链接错误
 */

Exercise::Type Exercise::setVal(Type parm) {
    val = parm + initVal();
    return val;
}

inline Exercise::Type Exercise::initVal() {
    return 1.0;
}

int main(void) {
    return 0;
}
