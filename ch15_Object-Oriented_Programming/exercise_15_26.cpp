/*
 * 定义Quote和Bulk_quote的拷贝控制成员，令其与合成的版本行为一致。
 * 为这些成员以及其他构造函数添加打印状态的语句，使得我们能够知道正在运行哪个程序。
 * 使用这些类编写程序，预测程序将创建和销毁哪些对象。
 * 重复实验，不断比较你的预测和实际输出结果是否相同，直到预测完全准确再结束。
 */

#include "include/Bulk_quote.h"
#include "include/Quote.h"
#include <type_traits>

int main(int argc, char const *argv[]) {
    Quote q1;
    Quote q2(q1);
    Quote q3;
    q3 = q2;
    Quote q4(std::move(q1));
    q3 = std::move(q4);
    Bulk_quote b1;
    Bulk_quote b2(b1);
    Bulk_quote b3;
    b3 = b2;
    Bulk_quote b4(std::move(b1));
    b3 = std::move(b4);
    return 0;
}
